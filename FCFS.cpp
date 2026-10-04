
#include <iostream>
using namespace std;

int main()
{
    int n, i, j;

    cout << "Enter number of process: ";
    cin >> n;

    int pid[100], AT[100], BT[100], CT[100], TAT[100], WT[100];

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

    cout << "\nGantt Chart: ";

    for(i = 0; i < n; i++)
    {
        // If CPU is idle
        if(time < AT[i])
        {
            time = AT[i];
        }

        // Completion Time
        time = time + BT[i];
        CT[i] = time;

        // Turnaround Time = CT - AT
        TAT[i] = CT[i] - AT[i];

        // Waiting Time = TAT - BT
        WT[i] = TAT[i] - BT[i];

        totalBT = totalBT + BT[i];

        T_WT = T_WT + WT[i];
        T_TAT = T_TAT + TAT[i];

        cout << "| P" << pid[i] << " ";
    }

    cout << "|\n";

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";

    for(i = 0; i < n; i++)
    {
        cout << "P" << pid[i]
             << "\t" << AT[i]
             << "\t" << BT[i]
             << "\t" << CT[i]
             << "\t" << TAT[i]
             << "\t" << WT[i] << "\n";
    }

    // Total time = Last Completion Time - First Arrival Time
    int totalTime = CT[n - 1] - AT[0];

    // Average Waiting Time
    cout << "\nAverage Waiting Time = "
         << T_WT / n << endl;

    // Average Turnaround Time
    cout << "Average Turnaround Time = "
         << T_TAT / n << endl;

    // Throughput
    float throughput = (float)n / totalTime;

    cout << "Throughput = "
         << throughput << " process/unit time" << endl;

    // CPU Utilization
    float utilization = ((float)totalBT / totalTime) * 100;

    cout << "CPU Utilization = "
         << utilization << "%" << endl;

    return 0;
}

