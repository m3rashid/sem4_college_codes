#include <bits/stdc++.h>
using namespace std;

struct timeSlice {
  int process_id;
  int start_time;
  int end_time;
};
struct process {
  int process_id;
  int burst_time;
  int arrival_time;
  int remaining_burst_time;
};
timeSlice time_slice[100];

bool compare(process a, process b) { return a.arrival_time < b.arrival_time; }

int sum(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

int main() {
  cout << endl
       << "This program was submiited by MD Rashid Hussain (20BCS033)" << endl;
  int process_count;
  cout << "Enter number of processes: ";
  cin >> process_count;

  int quantum_time;
  cout << "Enter quantum time: ";
  cin >> quantum_time;

  process p[process_count];
  for (int i = 0; i < process_count; i++) {
    cout << "Enter <arrival_time> <burst_time> for process P" << i + 1 << ": ";
    cin >> p[i].arrival_time >> p[i].burst_time;
    p[i].process_id = i + 1;
    p[i].remaining_burst_time = p[i].burst_time;
  }
  cout << endl;

  queue<process> ready_queue;
  int running_count = process_count;
  sort(p, p + running_count, compare);

  int slice_counter = 0;
  int time = p[0].arrival_time;
  ready_queue.push(p[0]);
  vector<int> completed;

  while (running_count > 0) {
    if (ready_queue.empty()) {
      int flag = 0;
      for (int i = 0; i < process_count; i++) {
        if (flag == 1) break;
        for (auto x : completed) {
          if (p[i].process_id != x) {
            ready_queue.push(p[i]);
            time = p[i].arrival_time;
            flag = 1;
            break;
          }
        }
      }
    }

    process temp = ready_queue.front();
    ready_queue.pop();

    timeSlice ts;
    ts.process_id = temp.process_id;
    ts.start_time = time;

    if (temp.remaining_burst_time > quantum_time) {
      temp.remaining_burst_time -= quantum_time;
      time += quantum_time;
    } else {
      time += temp.remaining_burst_time;
      temp.remaining_burst_time = 0;
      running_count--;
      completed.push_back(temp.process_id);
    }
    ts.end_time = time;
    time_slice[slice_counter++] = ts;

    for (int i = 0; i < running_count; i++) {
      if (
          p[i].arrival_time <= time &&
          p[i].process_id != temp.process_id) {
        ready_queue.push(p[i]);
      }
    }

    if (temp.remaining_burst_time > 0) {
      ready_queue.push(temp);
    }
  }

  int waiting_time[process_count];
  int turnaround_time[process_count];
  int completion_time[process_count];

  for (int i = 0; i < process_count; i++) {
    for (int j = slice_counter - 1; j > 0; j--) {
      if (time_slice[j].process_id == i + 1) {
        waiting_time[i] = time_slice[j].start_time - p[i].arrival_time;
        turnaround_time[i] = time_slice[j].end_time - p[i].arrival_time;
        completion_time[i] = time_slice[j].end_time;
        break;
      }
    }
  }

  float avg_waiting_time = sum(waiting_time, process_count) * 1.00 / process_count;
  float avg_turnaround_time = sum(turnaround_time, process_count) * 1.00 / process_count;
  float avg_completion_time = sum(completion_time, process_count) * 1.00 / process_count;

  cout << "Average waiting time: " << avg_waiting_time << endl;
  cout << "Average turnaround time: " << avg_turnaround_time << endl;
  cout << "Average completion time: " << avg_completion_time << endl;

  cout << endl
       << "Gantt Chart: " << endl
       << "|P" << time_slice[0].process_id;
  for (int i = time_slice[0].start_time; i < time_slice[0].end_time; i++) {
    cout << " ";
  }
  cout << "|";

  for (int i = 1; i < slice_counter; i++) {
    if (time_slice[i].start_time > time_slice[i - 1].end_time) {
      cout << " ";
      for (int j = time_slice[i - 1].end_time; j < time_slice[i].start_time; j++) {
        cout << "*";
      }
      cout << " |";
    }

    cout << "P" << time_slice[i].process_id;
    for (int j = 0; j < time_slice[i].end_time - time_slice[i].start_time;
         j++) {
      cout << " ";
    }
    cout << "|";
  }
  cout << endl;

  cout << time_slice[0].start_time;

  for (int i = 1; i < slice_counter; i++) {
    for (int j = time_slice[i].start_time; j < time_slice[i].end_time; j++) {
      cout << " ";
    }
    if (time_slice[i].start_time > time_slice[i - 1].end_time) {
      cout << time_slice[i - 1].end_time;
      for (int j = time_slice[i - 1].end_time; j < time_slice[i].start_time; j++) {
        cout << " ";
      }
    }
    cout << "  " << time_slice[i].start_time << " ";
  }
  for (int i = time_slice[slice_counter - 1].start_time; i < time_slice[slice_counter - 1].end_time; i++) {
    cout << " ";
  }
  cout << time_slice[slice_counter - 1].end_time << endl;

  cout << endl
       << endl
       << endl;
  return 0;
}
