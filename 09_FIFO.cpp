#include <iostream>
using namespace std;

int main()
{
    int n;

    cout<<"Enter number of pages: ";
    cin>>n;

    int pages[n];

    cout<<"Enter page reference string:\n";

    for(int i=0;i<n;i++)
    {
        cin>>pages[i];
    }

    int frames;

    cout<<"Enter number of frames: ";
    cin>>frames;

    int frame[frames];

    for(int i=0;i<frames;i++)
    {
        frame[i] = -1;
    }

    int index = 0;
    int faults = 0;
    int hits = 0;

    for(int i=0;i<n;i++)
    {
        bool found = false;

        // Check page hit
        for(int j=0;j<frames;j++)
        {
            if(frame[j] == pages[i])
            {
                found = true;
                hits++;
                break;
            }
        }

        // Page Fault
        if(!found)
        {
            frame[index] = pages[i];

            index = (index + 1) % frames;
            faults++;
        }

        // Print Frames
        cout<<"\n";

        for(int j=0;j<frames;j++)
        {
            cout<<frame[j]<<" ";
        }
    }

    cout<<"\n\nTotal Page Faults = "<<faults;

    cout<<"\nTotal Page Hits = "<<hits;

    return 0;
}