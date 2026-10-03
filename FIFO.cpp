#include<iostream>
using namespace std;
int main()
{
    int n,frame,frameArr[100],page[100];
    int i,j,k,pagehit=0,pagemiss=0,count=0,index=0;
    cout<<"Enter number of frame :";
    cin>>frame;
    cout<<"\nEnter number of page :";
    cin>>n;

    cout<<"\n Enter reference string :";
    for(i=0;i<n;i++)
    {
        cin>>page[i];
    }

    cout << "\nPage\tFrames\t\tResult\n";

    for(i=0;i<n;i++)
    {
        bool hit=false;
        for(j=0;j<count;j++)
        {
            if(frameArr[j]==page[i])
            {
                hit =true;
                break;
            }
        }
        if(hit==true)
    {
        pagehit++;
    }
    else{
pagemiss++;
 if(count<frame)
        {
            frameArr[ count++]=page[i];
        }

        else{
            frameArr[index]=page[i];
            index=(index+1)%frame;
        }
    }
    cout<<page[i]<<"\t";
for(k=0;k<count;k++)
{
    cout<<frameArr[k]<<" ";
}

cout << "\t\t" << (hit ? "HIT" : "MISS") << "\n";


    }

    



cout<<"Total hit :"<<pagehit<<"\n";
cout<<"Total miss :"<<pagemiss<<"\n";
cout<< "Hit  Ratio :"<<(float)pagehit/n<<"\n";
cout<< "Miss Ratio :"<<(float)pagemiss/n<<"\n";

return 0;



}