
#include<iostream>
using namespace std;

int main()
{
    int n, i, j;
    int AT[100], BT[100], RT[100];
    int Priority[100];
    int WT[100], TAT[100], CT[100], Pid[100];
    int FirstStart[100];

    cout << "Enter number of process : ";
    cin >> n;

    // Input
    for(i = 0; i < n; i++)
    {
        Pid[i] = i + 1;

        cout << "\nEnter arrival time of P" << Pid[i] << " : ";
        cin >> AT[i];

        cout << "Enter burst time of P" << Pid[i] << " : ";
        cin >> BT[i];

        cout << "Enter priority of P" << Pid[i] << " : ";
        cin >> Priority[i];

        RT[i] = BT[i];

        FirstStart[i] = -1;
    }

    int time = 0;
    int completed = 0;
    int totalBT = 0;

    float T_WT = 0;
    float T_TAT = 0;
    float T_RT = 0;

    // Total Burst Time
    for(i = 0; i < n; i++)
    {
        totalBT = totalBT + BT[i];
    }

    cout << "\nGantt Chart:\n";

    while(completed < n)
    {
        int index = -1;

        // Find highest priority process
        for(j = 0; j < n; j++)
        {
            if(AT[j] <= time && RT[j] > 0)
            {
                if(index == -1 ||
                   Priority[j] < Priority[index])
                {
                    index = j;
                }
            }
        }

        // No process available
        if(index == -1)
        {
            time++;
            continue;
        }

        // First CPU Start Time
        if(FirstStart[index] == -1)
        {
            FirstStart[index] = time;
        }

        cout << "| P" << Pid[index] << " ";

        // Execute for 1 unit
        RT[index]--;
        time++;

        // Process completed
        if(RT[index] == 0)
        {
            completed++;

            CT[index] = time;

            TAT[index] = CT[index] - AT[index];

            WT[index] = TAT[index] - BT[index];

            // Response Time
            int responseTime = FirstStart[index] - AT[index];

            T_WT += WT[index];
            T_TAT += TAT[index];
            T_RT += responseTime;
        }
    }

    cout << "|\n";

    // Output
    cout << "\nProcess\tAT\tBT\tPriority\tCT\tWT\tTAT\tRT\n";

    for(i = 0; i < n; i++)
    {
        int responseTime = FirstStart[i] - AT[i];

        cout << "P" << Pid[i]
             << "\t" << AT[i]
             << "\t" << BT[i]
             << "\t" << Priority[i]
             << "\t\t" << CT[i]
             << "\t" << WT[i]
             << "\t" << TAT[i]
             << "\t" << responseTime << "\n";
    }

    cout << "\nAverage Waiting Time = "
         << T_WT / n << endl;

    cout << "Average Turnaround Time = "
         << T_TAT / n << endl;

    cout << "Average Response Time = "
         << T_RT / n << endl;

    // Throughput
    float throughput = (float)n / time;

    cout << "Throughput = "
         << throughput << " process/unit time" << endl;

    // CPU Utilization
    float utilization = ((float)totalBT / time) * 100;

    cout << "CPU Utilization = "
         << utilization << "%" << endl;

    // Efficiency
    float efficiency = ((float)totalBT / time) * 100;

    cout << "Efficiency = "
         << efficiency << "%" << endl;

    return 0;
}

