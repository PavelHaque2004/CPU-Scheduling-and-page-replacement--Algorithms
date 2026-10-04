```cpp
#include <iostream>
using namespace std;

int main()
{
    int n, i, j;

    cout << "Enter number of process: ";
    cin >> n;

    int pid[100], AT[100], BT[100];
    int CT[100], TAT[100], WT[100], RT[100];

    // Input
    for(i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        cout << "\nEnter arrival time: ";
        cin >> AT[i];

        cout << "Enter burst time: ";
        cin >> BT[i];
    }

    // Bubble Sort according to Arrival Time
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(AT[j] > AT[j + 1])
            {
                swap(AT[j], AT[j + 1]);
                swap(BT[j], BT[j + 1]);
                swap(pid[j], pid[j + 1]);
            }
        }
    }

    int time = 0;
    int totalBT = 0;

    float T_WT = 0;
    float T_TAT = 0;
    float T_RT = 0;

    cout << "\nGantt Chart: ";

    // FCFS Scheduling
    for(i = 0; i < n; i++)
    {
        // CPU Idle
        if(time < AT[i])
        {
            time = AT[i];
        }

        // First time CPU gets the process
        RT[i] = time - AT[i];

        // Completion Time
        time = time + BT[i];
        CT[i] = time;

        // Turnaround Time
        TAT[i] = CT[i] - AT[i];

        // Waiting Time
        WT[i] = TAT[i] - BT[i];

        // Total Burst Time
        totalBT = totalBT + BT[i];

        // Total values
        T_WT = T_WT + WT[i];
        T_TAT = T_TAT + TAT[i];
        T_RT = T_RT + RT[i];

        cout << "| P" << pid[i] << " ";
    }

    cout << "|\n";

    // Table
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n";

    for(i = 0; i < n; i++)
    {
        cout << "P" << pid[i]
             << "\t" << AT[i]
             << "\t" << BT[i]
             << "\t" << CT[i]
             << "\t" << TAT[i]
             << "\t" << WT[i]
             << "\t" << RT[i] << "\n";
    }

    // Total Time
    int totalTime = CT[n - 1] - AT[0];

    // Average Waiting Time
    cout << "\nAverage Waiting Time = "
         << T_WT / n << endl;

    // Average Turnaround Time
    cout << "Average Turnaround Time = "
         << T_TAT / n << endl;

    // Average Response Time
    cout << "Average Response Time = "
         << T_RT / n << endl;

    // Throughput
    float throughput = (float)n / totalTime;

    cout << "Throughput = "
         << throughput << " process/unit time" << endl;

    // CPU Utilization
    float utilization = ((float)totalBT / totalTime) * 100;

    cout << "CPU Utilization = "
         << utilization << "%" << endl;

    // Efficiency
    float efficiency = ((float)totalBT / totalTime) * 100;

    cout << "Efficiency = "
         << efficiency << "%" << endl;

    return 0;
}
```
