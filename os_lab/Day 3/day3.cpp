#include <bits/stdc++.h>
using namespace std;

void interchange(
    int *a,
    int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

float average(
    int arr[],
    int count)
{
  float s = 0;
  for (int i = 0; i < count; ++i)
    s += arr[i];

  return s /= 5;
}

void sortingAlgo(
    int process[],
    int arrivalTime[],
    int burstTime[],
    int count)
{
  for (int i = 0; i < count; i++)
    for (int j = 0; j < count - i - 1; j++)
      if (arrivalTime[j] > arrivalTime[j + 1])
      {
        interchange(&arrivalTime[j], &arrivalTime[j + 1]);
        interchange(&process[j], &process[j + 1]);
        interchange(&burstTime[j], &burstTime[j + 1]);
      }
}

void Algorithm(
    int process[],
    int arrivalTime[],
    int burstTime[],
    int ct[],
    int wt[],
    int tat[],
    int count)
{
  int temp, val;
  ct[0] = arrivalTime[0] + burstTime[0];
  tat[0] = ct[0] - arrivalTime[0];
  wt[0] = tat[0] - burstTime[0];

  for (int i = 1; i < count; i++)
  {
    temp = ct[i - 1];
    int low = burstTime[i];
    for (int j = i; j < count; ++j)
    {
      if (temp >= arrivalTime[j] && low >= burstTime[j])
      {
        low = burstTime[j];
        val = j;
      }
    }
    ct[val] = temp + burstTime[val];
    tat[val] = ct[val] - arrivalTime[val];
    wt[val] = tat[val] - burstTime[val];

    interchange(&process[val], &process[i]);
    interchange(&arrivalTime[val], &arrivalTime[i]);
    interchange(&burstTime[val], &burstTime[i]);
    interchange(&ct[val], &ct[i]);
    interchange(&wt[val], &wt[i]);
    interchange(&tat[val], &tat[i]);
  }
}

int main()
{
  int num;
  int process[100], arrivalTime[100], burstTime[100], ct[100], wt[100], tat[100];

  cout << "\nProgram submitted by: MD Rashid Hussain (20BCS033)";
  cout << "\n\nEnter number of process: ";
  cin >> num;
  for (int i = 0; i < num; i++)
  {
    cout << "Enter <processID> <arrivalTime> <burstTime>: ";
    cin >> process[i];
    cin >> arrivalTime[i];
    cin >> burstTime[i];
  }

  sortingAlgo(process, arrivalTime, burstTime, num);
  Algorithm(process, arrivalTime, burstTime, ct, wt, tat, num);

  cout << "\nProcess\tBT\tAT\tCT\tWT\tTAT\tRT\n";
  for (int i = 0; i < num; ++i)
  {
    cout << "P" << process[i] << "\t" << burstTime[i] << "\t" << arrivalTime[i] << "\t" << ct[i] << "\t" << wt[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
  }

  cout << "\n";
  cout << "Average CT\t"
       << "Average WT\t"
       << "Average TAT\t"
       << "Average RT" << endl;
  cout << "   " << average(ct, num) << "\t\t   " << average(wt, num) << "\t\t   " << average(tat, num) << "\t\t   " << average(wt, num);
  cout << "\n\n\nGantt Chart\n\n|";

  for (int i = 0; i < num; ++i)
  {
    cout << "\t"
         << "P" << process[i] << "\t|";
  }

  cout << endl
       << "0\t\t";
  for (int i = 0; i < num; ++i)
  {
    cout << ct[i] << "\t\t";
  }

  cout << "\n\n\n";
  return 0;
}
