// Activity selection problem using struct and vector

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity
{
    int start;
    int finish;
};

void activitySelection(vector<Activity> &activities)
{
    sort(activities.begin(), activities.end(), [](const Activity &item1, const Activity &item2) {
        return item1.finish < item2.finish;
    });

    cout << "Following activities are selected:" << endl;

    // Choose the first activity immediately after the order
    int lastFinishTime = activities[0].finish;
    int activityCount = 1;

    cout << "(" << activities[0].start << ", " << activities[0].finish << ") ";

    // Choosing activities that do not interfere with the latest selected activity
    for (int i = 1; i < activities.size(); i++)
    {
        if (activities[i].start >= lastFinishTime)
        {
            cout << "(" << activities[i].start << ", " << activities[i].finish << ") ";

            lastFinishTime = activities[i].finish;
            activityCount++;
        }
    }
    cout << "\n\nTotal number of possible activities: " << activityCount << endl;
}

int main()
{
    vector<Activity> activities = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}, {6, 10}, {8, 11}};

    activitySelection(activities);

    return 0;
}