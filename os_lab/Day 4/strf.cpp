#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

vector<int> com;
vector<int> ind;
vector<int> cotime;
vector<int> freq;

int bufftime = 9999;
int f = 0, sf = 0, et = 0;

struct process
{
  int process_id;
  int arrival_time;
  int burst_time;
  int start_time;
  int completion_time;
  int turnaround_time;
  int waiting_time;
  int response_time;
};

void GantChartPrint();

int main()
{
  cout << "\nThis program is submitted by MD Rashid Hussain, 20BCS033\n";
  int x;
  struct process p[100];
  float avg_turnaround_time;
  float avg_waiting_time;
  float avg_response_time;
  float cpu_utilization;
  int total_turnaround_time = 0;
  int total_waiting_time = 0;
  int total_response_time = 0;
  int total_idle_time = 0;
  float throughput;
  int burst_remaining[100];
  int is_completed[100];
  memset(is_completed, 0, sizeof(is_completed));

  cout << setprecision(2) << fixed;
  cout << "Enter the number of processes: ";
  cin >> x;
  cout << "Enter id of the process : ";
  for (int i = 0; i < x; i++)
    cin >> p[i].process_id;

  cout << "Enter arrival time of the process : ";
  for (int i = 0; i < x; i++)
  {
    cin >> p[i].arrival_time;
    bufftime = min(bufftime, p[i].arrival_time);
  }
  cout << "Enter burst time of the process : ";
  for (int i = 0; i < x; i++)
  {
    cin >> p[i].burst_time;
    burst_remaining[i] = p[i].burst_time;
  }

  int current_time = 0;
  int completed = 0;
  int prev = 0;

  while (completed != x)
  {
    int idx = -1;
    int mn = 10000000;
    for (int i = 0; i < x; i++)
    {
      if (p[i].arrival_time <= current_time && is_completed[i] == 0)
      {
        if (burst_remaining[i] < mn)
        {
          mn = burst_remaining[i];
          idx = i;
        }
        if (burst_remaining[i] == mn && p[i].arrival_time < p[idx].arrival_time)
        {
          mn = burst_remaining[i];
          idx = i;
        }
      }
    }

    if (idx != -1)
    {
      if (burst_remaining[idx] == p[idx].burst_time)
      {
        p[idx].start_time = current_time;
        total_idle_time += p[idx].start_time - prev;
      }
      burst_remaining[idx] -= 1;
      current_time++;

      prev = current_time;
      if (p[idx].process_id != f)
      {
        ind.push_back(p[idx].process_id);
        f = p[idx].process_id;
      }
      com.push_back(p[idx].process_id);
      if (burst_remaining[idx] == 0)
      {
        p[idx].completion_time = current_time;
        p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
        p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
        p[idx].response_time = p[idx].start_time - p[idx].arrival_time;

        total_turnaround_time += p[idx].turnaround_time;
        total_waiting_time += p[idx].waiting_time;
        total_response_time += p[idx].response_time;

        is_completed[idx] = 1;
        completed++;
      }
    }
    else
      current_time++;
  }

  int min_arrival_time = 10000000;
  int max_completion_time = -1;
  for (int i = 0; i < x; i++)
  {
    min_arrival_time = min(min_arrival_time, p[i].arrival_time);
    max_completion_time = max(max_completion_time, p[i].completion_time);
  }

  avg_turnaround_time = (float)total_turnaround_time / x;
  avg_waiting_time = (float)total_waiting_time / x;
  avg_response_time = (float)total_response_time / x;

  cout << endl
       << endl;

  cout << "Id\t"
       << "AT\t"
       << "BT\t"
       << "RT\t"
       << "CT\t"
       << "TAT\t"
       << "WT\t"
       << "\n"
       << endl;

  for (int i = 0; i < x; i++)
  {
    cout << p[i].process_id << "\t" << p[i].arrival_time << "\t" << p[i].burst_time << "\t" << p[i].start_time << "\t" << p[i].completion_time << "\t" << p[i].turnaround_time << "\t" << p[i].waiting_time << "\t"
         << "\n"
         << endl;
  }
  cout << "Average Turnaround Time = " << avg_turnaround_time << endl;
  cout << "Average Waiting Time = " << avg_waiting_time << endl;
  cout << "Average Response Time = " << avg_response_time << endl;

  int ert = 0;
  int j = 0;
  int fre = 0;
  for (int i = 0; i < com.size();)
  {
    while (com[j] == com[i])
    {
      j++;
      ert = ert + 1;
      fre++;
    }
    i = j;
    cotime.push_back(ert);
    freq.push_back(fre);
    fre = 0;
  }
  GantChartPrint();
}

void GantChartPrint()
{
  int y = ind.size();
  cout << "\n";
  int i, j;
  if (bufftime == 9999)
    bufftime = 0;

  if (bufftime != 0)
  {
    printf(" ");
    for (j = 0; j < bufftime; j++)
      printf("--");
    printf(" ");
  }

  if (bufftime == 0)
    printf(" ");

  for (i = 0; i < y; i++)
  {
    for (j = 0; j < freq[i]; j++)
      printf("--");
    printf(" ");
  }
  printf("\n|");

  if (bufftime != 0)
  {
    for (j = 0; j < bufftime - 1; j++)
      printf(" ");
    printf("I%d", bufftime);
    for (j = 0; j < bufftime - 1; j++)
      printf(" ");
    printf("|");
  }

  for (i = 0; i < y; i++)
  {
    for (j = 0; j < freq[i] - 1; j++)
      printf(" ");
    printf("P%d", ind[i]);
    for (j = 0; j < freq[i] - 1; j++)
      printf(" ");
    printf("|");
  }
  printf("\n ");

  if (bufftime != 0)
  {
    for (j = 0; j < bufftime; j++)
      printf("--");
    printf(" ");
  }

  for (i = 0; i < y; i++)
  {
    for (j = 0; j < freq[i]; j++)
      printf("--");
    printf(" ");
  }
  printf("\n");

  if (bufftime != 0)
  {
    printf("0");
    for (j = 0; j < bufftime; j++)
      printf("  ");
  }

  printf("%d", bufftime);
  for (i = 0; i < y; i++)
  {
    for (j = 0; j < freq[i]; j++)
      printf("  ");
    if (cotime[i] > 9)
      printf("\b");
    printf("%d", cotime[i]);
  }
  printf("\n");
}