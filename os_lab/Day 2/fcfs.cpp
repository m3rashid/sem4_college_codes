#include <iostream>
using namespace std;

int main()
{
    int n, bt[20], wt[20], tat[20], arrival[20], complete[20], response[20], i, j;
    double avg_wt = 0, avg_tat = 0, avg_rt = 0, avg_ct;
    string process[20];
    cout << "MD Rashid Hussain (20BCS033)" << endl;
    cout << "Enter total number of processes: ";
    cin >> n;

    cout << "\nEnter Processes" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "]: ";
        cin >> process[i];
    }

    cout << "\nEnter Process Burst Time\n";
    for (i = 0; i < n; i++)
    {
        cout << "P[" << process[i] << "]: ";
        cin >> bt[i];
    }

    cout << "\nEnter Process Arrival Time\n";
    for (i = 0; i < n; i++)
    {
        cout << "P[" << process[i] << "]: ";
        cin >> arrival[i];
    }

    // sorting
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arrival[j] > arrival[j + 1])
            {

                int t = arrival[j];
                arrival[j] = arrival[j + 1];
                arrival[j + 1] = t;

                string u = process[j];
                process[j] = process[j + 1];
                process[j + 1] = u;

                int v = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = v;
            }
        }
    }

    //calculating completion time
    complete[0] = 0;
    for (i = 0; i < n; i++)
    {
        complete[i] += bt[i];
        complete[i + 1] = complete[i];
    }

    //calculating turnaround time
    for (int i = 0; i < n; i++)
    {
        tat[i] = complete[i] - arrival[i];
    }

    //calculating waiting time
    wt[0] = 0; //waiting time for first process is 0
    response[0] = wt[0];
    for (i = 1; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        response[i] = wt[i];
    }

    for (int i = 0; i < n; i++)
    {
        avg_wt += wt[i];
        avg_tat += tat[i];
        avg_ct += complete[i];
        tat[i] = complete[i] - arrival[i];
    }

    cout << "\nProcess\t\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\tResponse Time";

    for (i = 0; i < n; i++)
    {
        cout << "\nP[" << process[i] << "]"
             << "  \t\t" << bt[i] << "\t\t" << arrival[i] << "\t\t" << complete[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t" << response[i];
    }

    cout << "\n\nAverage Completion Time: " << avg_ct / n;
    cout << "\nAverage Waiting Time: " << avg_wt / n;
    cout << "\nAverage Turnaround Time: " << avg_tat / n;
    cout << "\nAverage Response Time: " << avg_wt / n;

    cout << "\n================Gantt Chart================\n";
    cout << " ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < bt[i]; j++)
            cout << "--";
        cout << " ";
    }
    cout << "\n|";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < bt[i] - 1; j++)
            cout << " ";
        cout << "P" << process[i];
        for (j = 0; j < bt[i] - 1; j++)
            cout << " ";
        cout << "|";
    }
    cout << "\n ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < bt[i]; j++)
            cout << "--";
        cout << " ";
    }
    cout << "\n"
         << "0";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < bt[i]; j++)
            cout << "  ";
        if (tat[i] > 9)
            cout << "\b";
        cout << complete[i];
    }
    cout << "\n\n\n";
    return 0;
}
