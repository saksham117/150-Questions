// This is a variation of Merge Overlapping Intervals
// But here we will only take the area that is common

// I can opimize on the space
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/discuss/93735/A-Concise-Template-for-%22Overlapping-Interval-Problem%22
// Sort intervals/pairs in increasing order of the start position.

// Scan the sorted intervals, and maintain an "active set" for overlapping intervals. At most times, we do not need to use an 
// explicit set to store them. Instead, we just need to maintain several key parameters, e.g. the number of overlapping 
// intervals (count), the minimum ending point among all overlapping intervals (minEnd).

// If the interval that we are currently checking overlaps with the active set, which can be characterized by cur.start > minEnd, 
// we need to renew those key parameters or change some states.

// If the current interval does not overlap with the active set, we just drop current active set, record some parameters, 
// and create a new active set that contains the current interval.

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

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        // sort the array
        sort(points.begin(), points.end());

        // stack to store the common intervals
        // the vector will be of size 2, where index 0 will represent Xstart and index[1] will represent Xend
        stack<vector<int>> s;

        // push first element into the stack
        s.push(points[0]);

        // so iterate over the complete points array
        for(int i = 1; i <= points.size(); i++){

            vector<int> topElement = s.top();
            
            // x start and x end of element at top of stack
            int x_start_top = topElement[0];
            int x_end_top = topElement[1];

            // x start and x end of the element we are noe considereing from the points vector
            int x_start = points[i][0];
            int x_end = points[i][1];

            // checking if there is some sort of overlap
            if(x_start <= x_end_top){
                // taking max and min to extract the common space between the two
                int new_x_start = max(x_start_top, x_start);
                int new_x_end = min(x_end_top, x_end);

                s.pop();
                vector<int> temp(2);
                temp[0] = new_x_start;
                temp[1] = new_x_end;
                s.push(temp);
            }
            // if there aint, simply make a new interval
            else{
                s.push(points[i]);
            }
        }

        // the number of arrows that need to be shot would be equal to the number of intervals in the stack
        return s.size();
        
    }
};