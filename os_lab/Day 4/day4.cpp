#include <bits/stdc++.h>
using namespace std;

struct process
{
  int process_id;
  int arrival_time;
  int burst_time;
  int remaining_time;

  int waiting_time;
  int completion_time;
  int total_arrival_time;
};

struct completed
{
  int start_time;
  int p_id;
  int end_time;
};

vector<process> ready;
vector<process> running;

void interchange(process *a, process *b);
void sortProcess(vector<process> &p);
void printProces(vector<process> &p);
void printCompleted(vector<completed> &c);
bool bTimeSort(process a, process b);

int main()
{
  cout << "\nThis program is submitted by MD Rashid Hussain, 20BCS033";
  int count;
  cout << "\nEnter number of process: ";
  cin >> count;

  vector<process> p;
  vector<completed> c;
  vector<process> waiting;

  /*
    0 8
    1 4
    2 2
    3 1
    4 3
    5 2
  */

  int at, bt;
  for (int i = 0; i < count; i++)
  {
    cout << "\nFor process " << i + 1;
    cout << ",\nEnter <arrival_time(int)> <burst_time(int)>: ";
    cin >> at >> bt;

    process temp;
    temp.process_id = i + 1;
    temp.arrival_time = at;
    temp.burst_time = bt;
    temp.remaining_time = bt;
    temp.waiting_time = 0;
    temp.completion_time = 0;
    temp.total_arrival_time = 0;
    p.push_back(temp);
  }

  sortProcess(p);
  cout << "\nAfter sort\n";
  printProces(p);

  cout << "\n\n";

  while (p.size() > 0)
  {
    for (int i = 0; i < p.size() - 1; i++)
    {
      sort(p.begin(), p.begin() + i, bTimeSort);

      int rm_diff = p[i + 1].remaining_time - p[i].remaining_time;
      if (rm_diff < 0)
      {
        interchange(&p[i], &p[i + 1]);
        continue;
      }

      if (rm_diff < p[i].remaining_time)
      {
        p[i].remaining_time -= rm_diff;
      }
      else
      {
        completed temp;
        temp.start_time = p[i].arrival_time;
        temp.p_id = p[i].process_id;
        temp.end_time = p[i].arrival_time + p[i].burst_time;
        c.push_back(temp);
        p.erase(p.begin() + i);
        cout << "\none process done";
        cout << "\nProcess " << temp.p_id << ": ";
        cout << "\nStart Time: " << temp.start_time;
        cout << "\nEnd Time: " << temp.end_time << "\n";
      }
    }
  }

  // cout << "\nAfter completion\n";
  // cout << "\nProcess\n";
  // printProces(p);

  cout << "\ncompleted Queue\n";
  printCompleted(c);
  return 0;
}

//
//
// function declaartions

void interchange(process *a, process *b)
{
  process temp = *a;
  *a = *b;
  *b = temp;
}

void sortProcess(vector<process> &p)
{
  for (int i = 0; i < p.size(); i++)
  {
    for (int j = 0; j < p.size() - i - 1; j++)
    {
      if (p[j].arrival_time > p[j + 1].arrival_time)
      {
        interchange(&p[j], &p[j + 1]);
      }
      if (
          p[j].arrival_time == p[j + 1].arrival_time &&
          p[j].burst_time > p[j + 1].burst_time)
      {
        interchange(&p[j], &p[j + 1]);
      }
    }
  }
}

void printProces(vector<process> &p)
{
  for (int i = 0; i < p.size(); i++)
  {
    cout << "\nProcess " << p[i].process_id << ": ";
    cout << "\nArrival Time: " << p[i].arrival_time;
    cout << "\nRemaining Time: " << p[i].remaining_time;
    cout << "\nBurst Time: " << p[i].burst_time << "\n";
  }
}

void printCompleted(vector<completed> &c)
{
  for (int i = 0; i < c.size(); i++)
  {
    cout << "\nProcess " << c[i].p_id << ": ";
    cout << "\nStart Time: " << c[i].start_time;
    cout << "\nEnd Time: " << c[i].end_time << "\n";
  }
}

bool bTimeSort(process a, process b)
{
  return a.burst_time < b.burst_time;
}