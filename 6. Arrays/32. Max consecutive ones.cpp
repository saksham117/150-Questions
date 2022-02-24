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

// pretty simple and straightforward

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count += 1;
            }
            else{
                count = 0;
            }

            if(count > maxCount){
                maxCount = count;
            }
        }
    }
};