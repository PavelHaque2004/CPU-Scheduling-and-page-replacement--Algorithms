#include<iostream>
using namespace std;

int main()
{
    int n, i;
    int AT[100], BT[100], TAT[100], WT[100];
    int RT[100], Pid[100], quantum, CT[100];

    cout << "Enter number of process : ";
    cin >> n;

    for(i = 0; i < n; i++)
    {
        Pid[i] = i + 1;

        cout << "\nEnter arrival time : ";
        cin >> AT[i];

        cout << "Enter burst time : ";
        cin >> BT[i];

        RT[i] = BT[i];
    }

    cout << "Enter time quantum : ";
    cin >> quantum;

    int time = 0;
    int completed = 0;
    int totalBT = 0;

    float T_WT = 0;
    float T_TAT = 0;

    // Total Burst Time
    for(i = 0; i < n; i++)
    {
        totalBT = totalBT + BT[i];
    }

    // Ready Queue
    int queue[1000];
    int front = 0;
    int rear = 0;

    bool inqueue[100] = {false};

    cout << "\nGantt chart :\n";

    while(completed < n)
    {
        // Add arrived processes to ready queue
        for(i = 0; i < n; i++)
        {
            if(AT[i] <= time &&
               RT[i] > 0 &&
               inqueue[i] == false)
            {
                queue[rear] = i;
                rear++;

                inqueue[i] = true;
            }
        }

        // CPU idle
        if(front == rear)
        {
            time++;
            continue;
        }

        // Take process from front of queue
        int index = queue[front];
        front++;

        cout << "| P" << Pid[index] << " ";

        // Running time
        int runtime;

        if(RT[index] > quantum)
        {
            runtime = quantum;
        }
        else
        {
            runtime = RT[index];
        }

        // Execute process
        RT[index] = RT[index] - runtime;
        time = time + runtime;

        // Add newly arrived processes
        for(i = 0; i < n; i++)
        {
            if(AT[i] <= time &&
               RT[i] > 0 &&
               inqueue[i] == false)
            {
                queue[rear] = i;
                rear++;

                inqueue[i] = true;
            }
        }

        // Process completed
        if(RT[index] == 0)
        {
            completed++;

            CT[index] = time;

            TAT[index] = CT[index] - AT[index];

            WT[index] = TAT[index] - BT[index];

            T_WT += WT[index];
            T_TAT += TAT[index];

            inqueue[index] = false;
        }

        // Process not completed
        else
        {
            queue[rear] = index;
            rear++;
        }
    }

    cout << "|\n";

    // Output
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";

    for(i = 0; i < n; i++)
    {
        cout << "P" << Pid[i]
             << "\t" << AT[i]
             << "\t" << BT[i]
             << "\t" << CT[i]
             << "\t" << TAT[i]
             << "\t" << WT[i] << "\n";
    }

    cout << "\nAverage Waiting Time = "
         << T_WT / n << endl;

    cout << "Average Turnaround Time = "
         << T_TAT / n << endl;

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