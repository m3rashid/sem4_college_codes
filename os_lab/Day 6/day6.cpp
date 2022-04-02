#include <bits/stdc++.h>
using namespace std;

struct process {
  pid_t process_no = 0;
  time_t start_arrival_time = 0, arrival_time = 0,
         burst_time_left = 0, burst_time = 0, temp_burst_time = 0,
         completion_time = 0, total_arrival_time = 0, waiting_time = 0, response_time = 0;
  int priority = 0;

  void set_completion_time(time_t time) {
    completion_time = time;
    set_total_arrival_time();
    set_waiting_time();
  }

  void set_total_arrival_time() {
    total_arrival_time = completion_time - start_arrival_time;
  }

  void set_waiting_time() {
    waiting_time = total_arrival_time - burst_time;
  }

  void set_process() {
    start_arrival_time = arrival_time;
    burst_time_left = burst_time;
  }

  void set_response_time(time_t time) {
    response_time = time - start_arrival_time;
  }

  friend bool operator<(const process& a, const process& b) {
    return a.arrival_time > b.arrival_time;
  }
};

process pop_index(priority_queue<process>* main_queue, int index) {
  priority_queue<process> rm_index;
  int i;
  process p;
  switch (index) {
    case 0:
      p = (*main_queue).top();
      (*main_queue).pop();
      break;
    default:
      for (i = 0; i < index; i++) {
        rm_index.push((*main_queue).top());
        (*main_queue).pop();
      }
      p = (*main_queue).top();
      (*main_queue).pop();

      while (!(*main_queue).empty()) {
        rm_index.push((*main_queue).top());
        (*main_queue).pop();
      }
      (*main_queue) = rm_index;
      break;
  }
  return p;
}

int max_priority(priority_queue<process> main_priority_queue, int limit, bool high) {
  int max = -1;
  if (high == 1) {
    while (!main_priority_queue.empty() && main_priority_queue.top().arrival_time <= limit) {
      if (main_priority_queue.top().priority > max)
        max = main_priority_queue.top().priority;
      main_priority_queue.pop();
    }
  } else {
    while (!main_priority_queue.empty() && main_priority_queue.top().arrival_time <= limit) {
      if (max == -1 || main_priority_queue.top().priority < max)
        max = main_priority_queue.top().priority;
      main_priority_queue.pop();
    }
  }
  return max;
}

int max_priority_index(priority_queue<process> main_queue, int limit, bool high) {
  int max = -1, i = 0, index = 0;
  if (high == 1) {
    while (!main_queue.empty() && main_queue.top().arrival_time <= limit) {
      if (main_queue.top().priority > max) {
        max = main_queue.top().priority;
        index = i;
      }
      main_queue.pop();
      i++;
    }
  } else {
    while (!main_queue.empty() && main_queue.top().arrival_time <= limit) {
      if (max == -1 || main_queue.top().priority < max) {
        max = main_queue.top().priority;
        index = i;
      }
      main_queue.pop();
      i++;
    }
  }
  return index;
}

priority_queue<process> Priority_NP_run(priority_queue<process> ready_queue, queue<process>* gantt, bool high) {
  priority_queue<process> completion_queue;
  process p;
  time_t clock = 0;
  if (high == 1) {
    while (!ready_queue.empty()) {
      while (clock < ready_queue.top().arrival_time) {
        p.temp_burst_time++;
        clock++;
      }
      if (p.temp_burst_time > 0) {
        p.process_no = -1;
        p.completion_time = clock;
        (*gantt).push(p);
      }
      p = pop_index(&ready_queue, max_priority_index(ready_queue, clock, high));
      p.set_response_time(clock);

      while (p.burst_time_left > 0) {
        p.temp_burst_time++;
        p.burst_time_left--;
        clock++;
      }
      p.set_completion_time(clock);
      (*gantt).push(p);
      p.temp_burst_time = 0;
      completion_queue.push(p);
    }
  } else {
    while (!ready_queue.empty()) {
      while (clock < ready_queue.top().arrival_time) {
        p.temp_burst_time++;
        clock++;
      }
      if (p.temp_burst_time > 0) {
        p.process_no = -1;
        p.completion_time = clock;
        (*gantt).push(p);
      }
      p = pop_index(&ready_queue, max_priority_index(ready_queue, clock, high));
      p.set_response_time(clock);

      while (p.burst_time_left > 0) {
        p.temp_burst_time++;
        p.burst_time_left--;
        clock++;
      }
      p.set_completion_time(clock);
      (*gantt).push(p);
      p.temp_burst_time = 0;
      completion_queue.push(p);
    }
  }
  return completion_queue;
}

priority_queue<process> set_sample_data() {
  priority_queue<process> ready_queue;
  int n;
  cout << "\nEnter the number of processes: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "Enter arrival time ,burst time and priority of process " << i + 1 << " : ";
    process temp;
    cin >> temp.arrival_time >> temp.burst_time >> temp.priority;
    temp.process_no = i + 1;
    temp.set_process();
    ready_queue.push(temp);
  }
  cout << "\n";
  return ready_queue;
}

double get_total_waiting_time(priority_queue<process> processes) {
  double total = 0;
  while (!processes.empty()) {
    total += processes.top().waiting_time;
    processes.pop();
  }
  return total;
}

double get_total__turnaround_time(priority_queue<process> processes) {
  double total = 0;
  while (!processes.empty()) {
    total += processes.top().total_arrival_time;
    processes.pop();
  }
  return total;
}

double get_total_completion_time(priority_queue<process> processes) {
  double total = 0;
  while (!processes.empty()) {
    total += processes.top().completion_time;
    processes.pop();
  }
  return total;
}

double get_total_response_time(priority_queue<process> processes) {
  double total = 0;
  while (!processes.empty()) {
    total += processes.top().response_time;
    processes.pop();
  }
  return total;
}

void display_chart(priority_queue<process> main_queue, bool high) {
  int i = 0, temp, size = main_queue.size();
  priority_queue<process> tempq = main_queue;
  double temp1;
  cout << "+-------------+--------------";
  cout << "+------------+-----------------";
  cout << "+-----------------+--------------+---------------+";
  if (high == true)
    cout << "----------+" << endl;
  else
    cout << endl;
  cout << "| Process No. | Arrival Time ";
  cout << "| Burst Time | Completion Time ";
  cout << "| Turnaround Time | Waiting Time | Response Time |";
  if (high == true)
    cout << " Priority |" << endl;
  else
    cout << endl;
  cout << "+-------------+--------------";
  cout << "+------------+-----------------";
  cout << "+-----------------+--------------+---------------+";
  if (high == true)
    cout << "----------+" << endl;
  else
    cout << endl;
  while (!main_queue.empty()) {
    temp = to_string(main_queue.top().process_no).length();
    cout << '|' << string(6 - temp / 2 - temp % 2, ' ')
         << main_queue.top().process_no << string(7 - temp / 2, ' ');
    temp = to_string(main_queue.top().start_arrival_time).length();
    cout << '|' << string(7 - temp / 2 - temp % 2, ' ')
         << main_queue.top().start_arrival_time << string(7 - temp / 2, ' ');
    temp = to_string(main_queue.top().burst_time).length();
    cout << '|' << string(6 - temp / 2 - temp % 2, ' ')
         << main_queue.top().burst_time << string(6 - temp / 2, ' ');
    temp = to_string(main_queue.top().completion_time).length();
    cout << '|' << string(8 - temp / 2 - temp % 2, ' ')
         << main_queue.top().completion_time << string(9 - temp / 2, ' ');
    temp = to_string(main_queue.top().total_arrival_time).length();
    cout << '|' << string(8 - temp / 2 - temp % 2, ' ')
         << main_queue.top().total_arrival_time << string(9 - temp / 2, ' ');
    temp = to_string(main_queue.top().waiting_time).length();
    cout << '|' << string(7 - temp / 2 - temp % 2, ' ')
         << main_queue.top().waiting_time << string(7 - temp / 2, ' ');
    temp = to_string(main_queue.top().response_time).length();
    cout << '|' << string(7 - temp / 2 - temp % 2, ' ')
         << main_queue.top().response_time << string(8 - temp / 2, ' ');
    if (high == true) {
      temp = to_string(main_queue.top().priority).length();
      cout << '|' << string(5 - temp / 2 - temp % 2, ' ')
           << main_queue.top().priority << string(5 - temp / 2, ' ');
    }
    cout << "|\n";
    main_queue.pop();
  }
  cout << "+-------------+--------------";
  cout << "+------------+-----------------";
  cout << "+-----------------+--------------+---------------+";
  if (high == true)
    cout << "----------+";
  cout << endl;
  temp1 = get_total_completion_time(tempq);
  cout << "\nTotal completion time :- " << temp1 << endl;
  cout << "Average completion time :- " << temp1 / size << endl;
  temp1 = get_total__turnaround_time(tempq);
  cout << "\nTotal turnaround time :- " << temp1 << endl;
  cout << "Average turnaround time :- " << temp1 / size << endl;
  temp1 = get_total_waiting_time(tempq);
  cout << "\nTotal waiting time :- " << temp1 << endl;
  cout << "Average waiting time :- " << temp1 / size << endl;
  temp1 = get_total_response_time(tempq);
  cout << "\nTotal response time :- " << temp1 << endl;
  cout << "Average response time :- " << temp1 / size << endl;
}

void disp_gantt_chart(queue<process> gantt) {
  int temp, prev = 0;
  queue<process> spaces = gantt;
  cout << "\n\nGantt Chart (IS indicates idle state) :- \n+";
  while (!spaces.empty()) {
    cout << string(to_string(spaces.front().process_no).length() + (spaces.front().process_no != -1) + 2 * spaces.front().temp_burst_time, '-') << "+";
    spaces.pop();
  }
  cout << "\n|";
  spaces = gantt;
  while (!spaces.empty()) {
    cout << string(spaces.front().temp_burst_time, ' ');
    if (spaces.front().process_no == -1)
      cout << "IS" << string(spaces.front().temp_burst_time, ' ') << '|';
    else
      cout << "P" << spaces.front().process_no << string(spaces.front().temp_burst_time, ' ') << '|';
    spaces.pop();
  }
  spaces = gantt;
  cout << "\n+";
  while (!spaces.empty()) {
    cout << string(to_string(spaces.front().process_no).length() + (spaces.front().process_no != -1) + 2 * spaces.front().temp_burst_time, '-') << "+";
    spaces.pop();
  }
  spaces = gantt;
  cout << "\n0";
  while (!spaces.empty()) {
    temp = to_string(spaces.front().completion_time).length();
    cout << string(to_string(spaces.front().process_no).length() + (spaces.front().process_no != -1) + 2 * spaces.front().temp_burst_time - temp / 2 - prev, ' ') << spaces.front().completion_time;
    prev = temp / 2 - temp % 2 == 0;
    spaces.pop();
  }
  cout << "\n\n";
}

int main() {
  cout << "\n\nThis program was submitted by 20BCS033, MD Rashid Hussain" << endl;
  priority_queue<process> ready_queue, completion_queue;
  queue<process> gantt;
  ready_queue = set_sample_data();
  completion_queue = Priority_NP_run(ready_queue, &gantt, true);
  display_chart(completion_queue, true);
  disp_gantt_chart(gantt);
  return 0;
}
