#include <iostream>
using namespace std;

int main()
{
    int memory;

    cout<<"Enter total memory size: ";
    cin>>memory;

    int remaining = memory;

    int process[100];
    int block[100];

    int n = 0;

    while(true)
    {
        int size;

        cout<<"\nEnter process size (0 to stop): ";
        cin>>size;

        if(size == 0){ break; }

        int buddy = 1;

        while(buddy < size){ buddy = buddy * 2; }

        if(buddy > remaining)
        {
            cout<<"Memory not sufficient\n";
            continue;
        }

        process[n] = size;
        block[n] = buddy;

        remaining -= buddy;

        cout<<"Process P"<<n+1<<" allocated"<<endl;

        cout<<"Buddy Block = "<<buddy<<endl;

        cout<<"Internal Fragmentation = "
            <<buddy - size<<endl;

        cout<<"Remaining Memory = "
            <<remaining<<endl;

        n++;

    }   
    cout<<"\nFinal Allocation:\n";

    cout<<"Process\tSize\tBuddy Block\n";

    for(int i=0;i<n;i++)
    {
        cout<<"P"<<i+1<<"\t"
            <<process[i]<<"\t"
            <<block[i]<<endl;
    }
    
    return 0;
   
}