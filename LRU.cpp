#include<iostream>
using namespace std;
int main()
{
    int frame,n,i,j,k,page[100],frameArr[100],recent[100],pagehit=0,pagemiss=0,count=0;
    cout<<"Enter number of frame :";
    cin>>frame;
    cout<<"\nEnter number of page :";
    cin>>n;
    cout<<"\nEnter reference string :";
    for(i=0;i<n;i++)
    {
        cin>>page[i];
    }
 cout << "\nPage\tFrames\n";

    for(i=0;i<n;i++)
    {
        bool hit =false;
        int hitindex=-1;
        for(j=0;j<count;j++)
        {
                if(frameArr[j]==page[i])
                {
                    hit =true;
                    hitindex=j;
                    break;
                }
        }

        if(hit)
        {
            pagehit++;
            recent[hitindex]=i;
        }
      else 
      {
        pagemiss++;
        if(count<frame)
        {
            frameArr[count]=page[i];
            recent[count]=i;
            count++;
        }
        else{
            int lruindex=0;
            int minrecent=recent[0];
            for(k=0;k<frame;k++)
            {
                if(recent[k]<minrecent)
                {
                    minrecent=recent[k];
                    lruindex=k;
                }
            }



            frameArr[lruindex]=page[i];
            recent[lruindex]=i;

        }

        
      }
      cout<<page[i]<<"\t";
        for(k=0;k<count;k++)
        {
            cout<<frameArr[k]<<" ";
        }
        cout<<(hit ? "Hit":"Miss")<<"\n";


    }
    cout << "\nTotal Page Hits: " << pagehit << "\n";
    cout << "Total Page Misses: " << pagemiss << "\n";
    cout << "Hit Ratio: " << (float)pagehit / n << "\n";
    cout << "Miss Ratio: " << (float)pagemiss / n << "\n";

    return 0;


}