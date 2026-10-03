#include<iostream>
using namespace std;

int main()
{
    int frame, n;
    int page[100], frameArr[100];

    cout << "Enter number of frame : ";
    cin >> frame;

    cout << "Enter number of page : ";
    cin >> n;

    cout << "Enter reference string : ";
    for(int i = 0; i < n; i++)
    {
        cin >> page[i];
    }

    for(int i = 0; i < frame; i++)
    {
        frameArr[i] = -1;
    }

    int pageHit = 0;
    int pageMiss = 0;

    for(int i = 0; i < n; i++)
    {
        bool found = false;

        // Check page hit
        for(int j = 0; j < frame; j++)
        {
            if(frameArr[j] == page[i])
            {
                found = true;
                pageHit++;
                break;
            }
        }

        // If page miss
        if(found == false)
        {
            pageMiss++;

            int replaceIndex = -1;

            // Find empty frame
            for(int j = 0; j < frame; j++)
            {
                if(frameArr[j] == -1)
                {
                    replaceIndex = j;
                    break;
                }
            }

            // If no empty frame
            if(replaceIndex == -1)
            {
                int farthest = -1;

                for(int j = 0; j < frame; j++)
                {
                    int k;

                    for(k = i + 1; k < n; k++)
                    {
                        if(frameArr[j] == page[k])
                        {
                            break;
                        }
                    }

                    if(k > farthest)
                    {
                        farthest = k;
                        replaceIndex = j;
                    }
                }
            }

            frameArr[replaceIndex] = page[i];
        }

        // Display frames
        cout << "\nPage " << page[i] << " : ";

        for(int j = 0; j < frame; j++)
        {
            if(frameArr[j] == -1)
                cout << "- ";
            else
                cout << frameArr[j] << " ";
        }
    }

    cout << "\n\nTotal Page Hit  = " << pageHit;
    cout << "\nTotal Page Miss = " << pageMiss;

    return 0;
}