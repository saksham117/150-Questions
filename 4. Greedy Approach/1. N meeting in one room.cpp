#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<unordered_set>

using namespace std;

// The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the 
// start time is 
// more than or equal to the finish time of the previously selected activity. 
// We can sort the activities according to their finishing time so
//  that we always consider the next activity as minimum finishing time activity.
// 1) Sort the activities according to their finishing time 
// 2) Select the first activity from the sorted array and print it. 
// 3) Do the following for the remaining activities in the sorted array. 
// …….a) If the start time of this activity is greater than or equal to the finish time of the 
// previously selected activity then select this activity and print it.


class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> timings; 

        // we are storing end time first and then start time coz we want to sort according to end time
        for(int i = 0; i < n; i++){
            timings.push_back({end[i], start[i]});
        }

        sort(timings.begin(), timings.end());

        int prev_end_time = -1;
        int jobs = 0;
        for(int i = 0; i < n; i++){
            if(timings[i].second > prev_end_time)
            {
                jobs += 1;
                prev_end_time = timings[i].first;
            }
        }
        return jobs;
    }
};