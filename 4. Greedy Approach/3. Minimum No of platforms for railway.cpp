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

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.

    // function to correct time if minutes > 59
    int helper(int time){    
        int minutes, hours;
        
        // extracting number of minutes
        minutes = time%10;
        time = time/10;
        minutes += 10*(time%10);
        time = time/10;
        
        // extracting number of hours
        hours = time%10;
        time = time/10;
        hours += 10*(time%10);
        time = time/10;
    
        // cout<<"Hours: "<<hours<<" Minutes: "<<minutes<<'\n';
        
        if(minutes >= 60)
        {
            minutes = minutes%60;
            hours = hours+1;
        }
        
        time = hours*100 + minutes;
        // cout<<"final time: "<<time<<'\n';
        return time;
    }

    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
        vector<pair<int, int>> train_times;

        for(int i = 0; i < n; i++)
        {
            int arrival = helper(arr[i]);
            int departure = helper(dep[i]);
            train_times.push_back({arrival, departure});
        }

        sort(train_times.begin(), train_times.end());

        vector<int> platforms;
        platforms.push_back(train_times[0].second);

        for(int i = 1; i < n; i++)
        {
            int newArrival = train_times[i].first;
            int newDeparture = train_times[i].second;
            bool possible = false;
            for(int j = 0; j < platforms.size(); j++)
            {
                if(newArrival > platforms[j])
                {
                    possible = true;
                    platforms[j] = newDeparture;
                    break;
                }
            }

            if(!possible){
                platforms.push_back(newDeparture);
            }
        }

        return platforms.size();

    }
};