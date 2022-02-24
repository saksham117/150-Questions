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
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int maxLen = 0;
        int sum = 0;
        unordered_map<int, int> hashMap;

        for(int i = 0; i < n; i++){
            sum += A[i];
            if(sum == 0){

                maxLen = max(maxLen, i + 1);
            }
            else if(hashMap.find(sum) != hashMap.end()){
                maxLen = max(i - hashMap[sum], maxLen);
            }
            else{
                hashMap[sum] = i;
            }
        }

        return maxLen;
    }
};