#include <iostream>
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

    int total = 0;

    cout<<"\nSeek Sequence: "<<head;

    for(int i=0;i<n;i++)
    {
        total += abs(req[i] - head);

        head = req[i];

        cout<<" -> "<<head;
    }

    cout<<"\nTotal Seek Time = "<<total;

    return 0;
}