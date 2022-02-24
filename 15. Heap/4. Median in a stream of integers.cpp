#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>
#include<map>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
          
    }
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;  
    
    void addNum(int num) {
        
        if(maxHeap.size() == 0)
        {
            maxHeap.push(num);
        }
        
        else if(num <= maxHeap.top())
        {
            maxHeap.push(num);
            
            if(maxHeap.size() - minHeap.size() > 1)
            {
                int t = maxHeap.top();
                maxHeap.pop();
                minHeap.push(t);
            }
        }
        
        else if(num > maxHeap.top())
        {
            minHeap.push(num);
            
            if(minHeap.size() - maxHeap.size() > 1)
            {
                int t = minHeap.top();
                minHeap.pop();
                maxHeap.push(t);
            }
        }
        
    }
    
    double findMedian() {
        
        if(maxHeap.size() > minHeap.size())
        {
            return maxHeap.top();
        }
        
        else if(maxHeap.size() < minHeap.size())
        {
            return minHeap.top();
        }
        else
        {
            double ans = maxHeap.top() + minHeap.top();
            ans = ans/2.0;
            return ans;
        }
    }
};