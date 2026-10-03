#include<iostream>
using namespace std;

int main()
{
    int n, i, j;
    int AT[100], BT[100], TAT[100], WT[100], Pid[100];

    cout << "Enter number of process : ";
    cin >> n;

    for(i = 0; i < n; i++)
    {
        Pid[i] = i + 1;

        cout << "\nEnter arrival time : ";
        cin >> AT[i];

        cout << "Enter burst time : ";
        cin >> BT[i];
    }

    int time = 0;
    float T_WT = 0;

    // SJF Non-Preemptive

    for(i = 0; i < n; i++)
    {
        int index = -1;

        // Find process with shortest burst time
        for(j = 0; j < n; j++)
        {
            if(AT[j] <= time && BT[j] > 0)
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

        // Calculate Waiting Time
        WT[index] = time - AT[index];

        // Calculate Turnaround Time
        TAT[index] = WT[index] + BT[index];

        cout << "| P" << Pid[index] << " ";

        // CPU executes the selected process
        time = time + BT[index];

        T_WT += WT[index];

        // Mark process as completed
        BT[index] = -1;
    }

    cout << "|\n";

    cout << "\nProcess\tAT\tWT\tTAT\n";

    for(i = 0; i < n; i++)
    {
        cout << "P" << Pid[i]
             << "\t" << AT[i]
             
             << "\t" << WT[i]
             << "\t" << TAT[i] << "\n";
    }

    cout << "\nAverage waiting time : "
         << T_WT / n << endl;

    return 0;
}