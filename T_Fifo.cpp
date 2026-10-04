#include<iostream>
using namespace std;

int main()
{
    int frame,n,i,j,k;
    int page[100],frameArr[100];
    int pagehit=0,pagemiss=0,count=0;

    cout<<"Enter number of frame :";
    cin>>frame;

    cout<<"\nEnter number of page :";
    cin>>n;

    cout<<"\nEnter reference string :";
    for(i=0;i<n;i++)
    {
        cin>>page[i];
    }

    cout << "\nPage\tFrames\tResult\n";

    for(i=0;i<n;i++)
    {
        bool hit=false;

        // Check Page Hit
        for(j=0;j<count;j++)
        {
            if(frameArr[j]==page[i])
            {
                hit=true;
                break;
            }
        }

        if(hit)
        {
            pagehit++;
        }

        else
        {
            pagemiss++;

            // Empty frame available
            if(count<frame)
            {
                frameArr[count]=page[i];
                count++;
            }

            // All frames are full
            else
            {
                int replaceIndex=0;
                int farthest=-1;

                for(j=0;j<frame;j++)
                {
                    int nextUse=n;

                    // Find next use of current frame page
                    for(k=i+1;k<n;k++)
                    {
                        if(frameArr[j]==page[k])
                        {
                            nextUse=k;
                            break;
                        }
                    }

                    // Find page used farthest in future
                    if(nextUse>farthest)
                    {
                        farthest=nextUse;
                        replaceIndex=j;
                    }
                }

                frameArr[replaceIndex]=page[i];
            }
        }

        // Display current page and frames
        cout<<page[i]<<"\t";

        for(k=0;k<count;k++)
        {
            cout<<frameArr[k]<<" ";
        }

        cout<<"\t"<<(hit ? "Hit":"Miss")<<"\n";
    }

    cout << "\nTotal Page Hits: " << pagehit << "\n";
    cout << "Total Page Misses: " << pagemiss << "\n";
    cout << "Hit Ratio: " << (float)pagehit / n << "\n";
    cout << "Miss Ratio: " << (float)pagemiss / n << "\n";

    return 0;
}