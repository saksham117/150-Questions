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
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        int sum = 0;
        unordered_map<int, int> hashMap;

        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(hashMap.find(sum) != hashMap.end() || sum == 0){
                return true;
            }
            else{
                hashMap[sum] = i;
            }
        }

        return false;
    }
};