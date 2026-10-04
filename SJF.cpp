// #include<iostream>
// using namespace std;

// int main()
// {
//     int n, i, j;
//     int AT[100], BT[100], TAT[100], WT[100], Pid[100];

//     cout << "Enter number of process : ";
//     cin >> n;

//     for(i = 0; i < n; i++)
//     {
//         Pid[i] = i + 1;

//         cout << "\nEnter arrival time : ";
//         cin >> AT[i];

//         cout << "Enter burst time : ";
//         cin >> BT[i];
//     }

//     int time = 0;
//     float T_WT = 0;

//     // SJF Non-Preemptive

//     for(i = 0; i < n; i++)
//     {
//         int index = -1;

//         // Find process with shortest burst time
//         for(j = 0; j < n; j++)
//         {
//             if(AT[j] <= time && BT[j] > 0)
//             {
//                 if(index == -1 || BT[j] < BT[index])
//                 {
//                     index = j;
//                 }
//             }
//         }

//         // No process is available
//         if(index == -1)
//         {
//             time++;
//             i--;
//             continue;
//         }

//         // Calculate Waiting Time
//         WT[index] = time - AT[index];

//         // Calculate Turnaround Time
//         TAT[index] = WT[index] + BT[index];

//         cout << "| P" << Pid[index] << " ";

//         // CPU executes the selected process
//         time = time + BT[index];

//         T_WT += WT[index];

//         // Mark process as completed
//         BT[index] = -1;
//     }

//     cout << "|\n";

//     cout << "\nProcess\tAT\tWT\tTAT\n";

//     for(i = 0; i < n; i++)
//     {
//         cout << "P" << Pid[i]
//              << "\t" << AT[i]
             
//              << "\t" << WT[i]
//              << "\t" << TAT[i] << "\n";
//     }

//     cout << "\nAverage waiting time : "
//          << T_WT / n << endl;

//     return 0;
// }










#include<iostream>
using namespace std;

int main()
{
    int n, i, j;

    int AT[100], BT[100], CT[100];
    int TAT[100], WT[100], RT[100];
    int Pid[100], completed[100];

    cout << "Enter number of process : ";
    cin >> n;

    // Input
    for(i = 0; i < n; i++)
    {
        Pid[i] = i + 1;
        completed[i] = 0;

        cout << "\nEnter arrival time : ";
        cin >> AT[i];

        cout << "Enter burst time : ";
        cin >> BT[i];
    }

    int time = 0;
    int totalBT = 0;

    float T_WT = 0;
    float T_TAT = 0;
    float T_RT = 0;

    cout << "\nGantt Chart: ";

    // SJF Non-Preemptive
    for(i = 0; i < n; i++)
    {
        int index = -1;

        // Find shortest burst time among available processes
        for(j = 0; j < n; j++)
        {
            if(AT[j] <= time && completed[j] == 0)
            {
                if(index == -1 || BT[j] < BT[index])
                {
                    index = j;
                }
            }
        }

        // No process is available
        if(index == -1)
        {
            time++;
            i--;
            continue;
        }

        // Response Time
        RT[index] = time - AT[index];

        // CPU executes the selected process
        time = time + BT[index];

        // Completion Time
        CT[index] = time;

        // Turnaround Time
        TAT[index] = CT[index] - AT[index];

        // Waiting Time
        WT[index] = TAT[index] - BT[index];

        // Total Burst Time
        totalBT = totalBT + BT[index];

        // Total values
        T_WT = T_WT + WT[index];
        T_TAT = T_TAT + TAT[index];
        T_RT = T_RT + RT[index];

        cout << "| P" << Pid[index] << " ";

        // Mark process as completed
        completed[index] = 1;
    }

    cout << "|\n";

    // Display Table
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n";

    for(i = 0; i < n; i++)
    {
        cout << "P" << Pid[i]
             << "\t" << AT[i]
             << "\t" << BT[i]
             << "\t" << CT[i]
             << "\t" << TAT[i]
             << "\t" << WT[i]
             << "\t" << RT[i] << "\n";
    }

    // Total Time
    int totalTime = CT[0];

    for(i = 1; i < n; i++)
    {
        if(CT[i] > totalTime)
        {
            totalTime = CT[i];
        }
    }

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
         << throughput
         << " process/unit time" << endl;

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

