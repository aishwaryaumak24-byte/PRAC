#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;

    cout<<"Enter number of requests: ";
    cin>>n;

    int req[n];
    bool done[n];

    cout<<"Enter requests:\n";

    for(int i=0;i<n;i++)
    {
        cin>>req[i];
        done[i] = false;
    }

    int head;

    cout<<"Enter initial head position: ";
    cin>>head;

    int total = 0;

    cout<<"\nSeek Sequence: "<<head;

    for(int i=0;i<n;i++)
    {
        int index = -1;
        int min = 9999;

        for(int j=0;j<n;j++)
        {
            if(!done[j])
            {
                int dist = abs(req[j] - head);

                if(dist < min)
                {
                    min = dist;
                    index = j;
                }
            }
        }

        total += abs(req[index] - head);

        head = req[index];

        done[index] = true;

        cout<<" -> "<<head;
    }

    cout<<"\nTotal Seek Time = "<<total;

    return 0;
}