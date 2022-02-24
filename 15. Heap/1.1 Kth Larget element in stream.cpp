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
// very simple
// just use a min heap and same logic as finding k largets and k smallets elements
class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        int i = 0;
        
        if(nums.size() != 0){
            while( i < k && i < nums.size()){
                this->minHeap.push(nums[i]);
                cout<<minHeap.top();
                i+=1;
            }

            for(; i < nums.size(); i++){
                this->minHeap.push(nums[i]);
                cout<<minHeap.top();
                this->minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        this->minHeap.push(val);
        if(this->minHeap.size() > this->k){
            minHeap.pop();
        }
        return this->minHeap.top();
        
    }
};