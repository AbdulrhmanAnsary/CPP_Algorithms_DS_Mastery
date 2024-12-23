// Activity selection problem using two sorted arrays

#include <iostream>

using namespace std;

void printSelectedActivities(const int startTimes[], const int finishTimes[], int numActivities)
{
    cout << "Selected activities are:\n";

    // Choose the first activity immediately after the order
    int lastSelectedActivity = 0;
    int activityCount = 1;

    // Print the first activity directly
    cout << "(" << startTimes[0] << ", " << finishTimes[0] << ") ";

    // Loop through the rest of the activities and select non-overlapping ones
    for (int currentActivity = 1; currentActivity < numActivities; currentActivity++)
    {
        if (startTimes[currentActivity] >= finishTimes[lastSelectedActivity])
        {
            cout << "(" << startTimes[currentActivity]
                 << ", " << finishTimes[currentActivity] << ") ";

            lastSelectedActivity = currentActivity;
            activityCount++;
        }
    }

    cout << "\n\nTotal number of possible activities: " << activityCount << endl;
}

int main()
{
    int startTimes[] = {1, 3, 0, 5, 8, 5};
    int finishTimes[] = {2, 4, 6, 7, 9, 9};
    int numActivities = sizeof(startTimes) / sizeof(startTimes[0]);

    printSelectedActivities(startTimes, finishTimes, numActivities);

    return 0;
}