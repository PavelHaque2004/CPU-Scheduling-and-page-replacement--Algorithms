```cpp
#include<iostream>
using namespace std;

int main()
{
    int n, i, j;
    int AT[100], BT[100], RT[100];
    int WT[100], TAT[100], Pid[100];

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

        RT[i] = BT[i];   // Remaining Time
    }

    int time = 0;
    int completed = 0;
    int totalBT = 0;

    float T_WT = 0;

    // Calculate Total Burst Time
    for(i = 0; i < n; i++)
    {
        totalBT = totalBT + BT[i];
    }

    cout << "\nGantt Chart:\n";

    while(completed < n)
    {
        int index = -1;

        // Find process with shortest remaining time
        for(j = 0; j < n; j++)
        {
            if(AT[j] <= time && RT[j] > 0)
            {
                if(index == -1 || RT[j] < RT[index])
                {
                    index = j;
                }
            }
        }

        // No process is available
        if(index == -1)
        {
            time++;
            continue;
        }

        // Execute process for 1 unit
        cout << "| P" << Pid[index] << " ";

        RT[index]--;
        time++;

        // Process completed
        if(RT[index] == 0)
        {
            completed++;

            TAT[index] = time - AT[index];

            WT[index] = TAT[index] - BT[index];

            T_WT += WT[index];
        }
    }

    cout << "|\n";

    // Output
    cout << "\nProcess\tAT\tBT\tWT\tTAT\n";

    for(i = 0; i < n; i++)
    {
        cout << "P" << Pid[i]
             << "\t" << AT[i]
             << "\t" << BT[i]
             << "\t" << WT[i]
             << "\t" << TAT[i] << "\n";
    }

    cout << "\nAverage Waiting Time = "
         << T_WT / n << endl;

    // Throughput
    float throughput = (float)n / time;

    cout << "Throughput = "
         << throughput
         << " process/unit time" << endl;

    // CPU Utilization
    float utilization = ((float)totalBT / time) * 100;

    cout << "CPU Utilization = "
         << utilization << "%" << endl;

    return 0;
}
```
