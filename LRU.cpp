#include <iostream>
using namespace std;

int main()
{
    int frames, n;

    cout << "Enter number of frames: ";
    cin >> frames;

    cout << "Enter number of pages: ";
    cin >> n;

    
    int pages[100];
    int framesArr[100];
    int recent[100];

    cout << "Enter page references: ";
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    int count = 0;
    int pageHits = 0;
    int pageMisses = 0;

    cout << "\nPage\tFrames\t\tStatus\n";
    cout << "--------------------------------\n";

    // Process each page
    for (int i = 0; i < n; i++)
    {
        bool hit = false;
        int hitIndex = -1;

        // Check whether page is already in frame
        for (int j = 0; j < count; j++)
        {
            if (framesArr[j] == pages[i])
            {
                hit = true;
                hitIndex = j;
                break;
            }
        }

        // If page is found
        if (hit)
        {
            pageHits++;

            // Update recent use time
            recent[hitIndex] = i;
        }

        // If page is not found
        else
        {
            pageMisses++;

            // If there is an empty frame
            if (count < frames)
            {
                framesArr[count] = pages[i];
                recent[count] = i;
                count++;
            }

            // If all frames are full
            else
            {
                int lruIndex = 0;
                int minRecent = recent[0];

                // Find Least Recently Used page
                for (int k = 1; k < frames; k++)
                {
                    if (recent[k] < minRecent)
                    {
                        minRecent = recent[k];
                        lruIndex = k;
                    }
                }

                // Replace LRU page
                framesArr[lruIndex] = pages[i];
                recent[lruIndex] = i;
            }
        }

        // Display current page and frames
        cout << pages[i] << "\t";

        for (int k = 0; k < count; k++)
        {
            cout << framesArr[k] << " ";
        }

        if (hit)
            cout << "\tHit";
        else
            cout << "\tMiss";

        cout << endl;
    }

    // Display final result
    cout << "\n--------------------------------\n";
    cout << "Total Page Hits   : " << pageHits << endl;
    cout << "Total Page Misses : " << pageMisses << endl;

    cout << "Hit Ratio         : "
         << (float)pageHits / n << endl;

    cout << "Miss Ratio        : "
         << (float)pageMisses / n << endl;

    return 0;
}