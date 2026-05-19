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

    int frame[frames], used[frames];

    for(int i=0;i<frames;i++)
    {
        frame[i] = -1;
        used[i] = -1;
    }

    int faults = 0;
    int hits = 0;

    for(int i=0;i<n;i++)
    {
        bool found = false;

        // Check Hit
        for(int j=0;j<frames;j++)
        {
            if(frame[j] == pages[i])
            {
                found = true;
                used[j] = i;
                hits++;
                break;
            }
        }

        // Page Fault
        if(!found)
        {
            int pos = -1;

            // Find Empty Frame First
            for(int j=0;j<frames;j++)
            {
                if(frame[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            // If no empty frame → apply LRU
            if(pos == -1)
            {
                pos = 0;

                for(int j=1;j<frames;j++)
                {
                    if(used[j] < used[pos])
                    {
                        pos = j;
                    }
                }
            }

            frame[pos] = pages[i];
            used[pos] = i;

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