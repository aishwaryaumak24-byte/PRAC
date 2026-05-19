#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, tq;
    cout<<"Enter number of processes: ";
    cin>>n;

    int at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Arrival time of P"<<i+1<<": ";
        cin>>at[i];

        cout<<"Burst time of P"<<i+1<<": ";
        cin>>bt[i];

        rt[i] = bt[i];
    }

    cout<<"Enter Time Quantum: ";
    cin>>tq;

    queue<int> q;
    bool visited[n] = {false};

    int time = 0, done = 0;

    while(done < n)
    {
        for(int i=0;i<n;i++)
        {
            if(at[i] <= time && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }

        if(q.empty())
        {
            time++;
            continue;
        }

        int i = q.front();
        q.pop();

        if(rt[i] > tq)
        {
            time += tq;
            rt[i] -= tq;
        }
        else
        {
            time += rt[i];
            rt[i] = 0;
            ct[i] = time;
            done++;
        }

        for(int j=0;j<n;j++)
        {
            if(at[j] <= time && !visited[j])
            {
                q.push(j);
                visited[j] = true;
            }
        }

        if(rt[i] > 0)
            q.push(i);
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