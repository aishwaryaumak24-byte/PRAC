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
                hits++;
                break;
            }
        }

        // Page Fault
        if(!found)
        {
            int pos = -1;

            // Find Empty Frame
            for(int j=0;j<frames;j++)
            {
                if(frame[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            // Apply Optimal
            if(pos == -1)
            {
                int farthest = -1;

                for(int j=0;j<frames;j++)
                {
                    int k;

                    for(k=i+1;k<n;k++)
                    {
                        if(frame[j] == pages[k])
                        {
                            if(k > farthest)
                            {
                                farthest = k;
                                pos = j;
                            }
                            break;
                        }
                    }

                    // Page not used again
                    if(k == n)
                    {
                        pos = j;
                        break;
                    }
                }
            }

            frame[pos] = pages[i];

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