#include<iostream>
using namespace std;
int main()
{

int i,j,frame ,n;
int frameArr[100],page[100],pagehit=0,pagemiss=0,count=0;

cout<<"Enter number of frame :";
cin>>frame;
cout<<"\nEnter number of page :";
cin>>n;
cout<<"\nstring :";
for(i=0;i<n;i++)
{
cin>>page[i];
}


cout<<"\n page \t frames\n";


for(i=0;i<n;i++)
{
    bool hit =false;

    for(j=0;j<count;j++)
    {
        if(frameArr[j]==page[i])
        {
            hit =true;
            break;
        }
    }



if(hit)
{
    pagehit++
}


else
{
    pagemiss++;

    if(count<frame)
    {
        frameArr[count]=page[i];
        count++;
    }


    else
    {
        int replaceindex=0;
        int future=-1;

        for(j=0;j<frame;j++)
        {
            int nextuse=n;

            for(int k=i+1;k<n;k++)
            {
                frameArr[j]==page[k];
                nextuse=k;
                break;
            }
        }


        
    }
}










}





}