#include<iostream>
using namespace std;

int main()
{
    int n, i, j;
    int AT[100], BT[100], RT[100];
    int Priority[100];
    int WT[100], TAT[100], CT[100], Pid[100];

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
    }

    int time = 0;
    int completed = 0;
    float T_WT = 0;

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

            T_WT += WT[index];
        }
    }

    cout << "|\n";

    // Output
    cout << "\nProcess\tAT\tBT\tPriority\tCT\tWT\tTAT\n";

    for(i = 0; i < n; i++)
    {
        cout << "P" << Pid[i]
             << "\t" << AT[i]
             << "\t" << BT[i]
             << "\t" << Priority[i]
             << "\t\t" << CT[i]
             << "\t" << WT[i]
             << "\t" << TAT[i] << "\n";
    }

    cout << "\nAverage Waiting Time = "
         << T_WT / n << endl;

    return 0;
}