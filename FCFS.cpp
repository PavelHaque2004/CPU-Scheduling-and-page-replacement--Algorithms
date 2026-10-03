#include <iostream>
using namespace std;

int main()
{
    int n, i, j;

    cout << "Enter number of process: ";
    cin >> n;

    int pid[100], AT[100], BT[100], TAT[100], WT[100];

    for(i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        cout << "\nEnter arrival time: ";
        cin >> AT[i];

        cout << "Enter burst time: ";
        cin >> BT[i];
    }

    // Bubble Sort
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
    float T_WT = 0;

    cout << "\nGantt Chart: ";

    for(i = 0; i < n; i++)
    {
        if(time < AT[i])
        {
            time = AT[i];
        }

        WT[i] = time - AT[i];

        TAT[i] = WT[i] + BT[i];

        time = time + BT[i];

        T_WT = T_WT + WT[i];

        cout << "| P" << pid[i] << " ";
    }

    cout << "|\n";

    cout << "\nProcess\tAT\tBT\tWT\tTAT\n";

    for(i = 0; i < n; i++)
    {
        cout << "P" << pid[i]
             << "\t" << AT[i]
             << "\t" << BT[i]
             << "\t" << WT[i]
             << "\t" << TAT[i] << "\n";
    }

    cout << "\nAverage Waiting Time = " << T_WT / n << endl;

    return 0;
}