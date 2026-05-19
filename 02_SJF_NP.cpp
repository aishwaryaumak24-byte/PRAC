#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;

    int at[n], bt[n];
    int ct[n], tat[n], wt[n];
    bool completed[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Arrival time of P"<<i+1<<": ";
        cin>>at[i];

        cout<<"Burst time of P"<<i+1<<": ";
        cin>>bt[i];

        completed[i] = false;
    }

    int time = 0, done = 0;

    while(done < n)
    {
        int shortest = -1;
        int minBT = INT_MAX;

        for(int i=0;i<n;i++)
        {
            if(at[i] <= time && !completed[i] && bt[i] < minBT)
            {
                minBT = bt[i];
                shortest = i;
            }
        }

        if(shortest == -1)
        {
            time++;
        }
        else
        {
            ct[shortest] = time + bt[shortest];
            time = ct[shortest];

            completed[shortest] = true;
            done++;
        }
    }

    float avgWT = 0, avgTAT = 0;

    for(int i=0;i<n;i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    avgWT /= n;
    avgTAT /= n;

    cout<<"\nProcess\tAT\tBT\tCT\tTAT\tWT\n";

    for(int i=0;i<n;i++)
    {
        cout<<"P"<<i+1<<"\t"
            <<at[i]<<"\t"
            <<bt[i]<<"\t"
            <<ct[i]<<"\t"
            <<tat[i]<<"\t"
            <<wt[i]<<endl;
    }

    cout<<"\nAverage Waiting Time = "<<avgWT<<endl;
    cout<<"Average Turnaround Time = "<<avgTAT<<endl;

    return 0;
}