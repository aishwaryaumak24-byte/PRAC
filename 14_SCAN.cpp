#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;

    cout<<"Enter number of requests: ";
    cin>>n;

    int req[n];

    cout<<"Enter requests:\n";

    for(int i=0;i<n;i++)
    {
        cin>>req[i];
    }

    int head;

    cout<<"Enter initial head position: ";
    cin>>head;

    sort(req, req+n);

    int total = 0;

    cout<<"\nSeek Sequence: "<<head;

    int index;

    for(index=0;index<n;index++)
    {
        if(req[index] > head)
        {
            break;
        }
    }

    for(int i=index-1;i>=0;i--)
    {
        total += abs(req[i] - head);

        head = req[i];

        cout<<" -> "<<head;
    }

    total += abs(head - 0);

    head = 0;

    cout<<" -> "<<head;

    for(int i=index;i<n;i++)
    {
        total += abs(req[i] - head);

        head = req[i];

        cout<<" -> "<<head;
    }

    cout<<"\nTotal Seek Time = "<<total;

    return 0;
}