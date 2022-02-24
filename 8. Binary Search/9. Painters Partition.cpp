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

// a copy of book allocation

class Solution
{
  public:
    bool isPossible(int arr[], int n, int k, long long limit){
        
        int painters = 1;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] > limit){
                return false; // if one element becomes greater than barries itself, then we cannot do anything
                // have to return false
            }
            if((long long)(sum + arr[i]) <= limit){
                sum = sum + arr[i];
            }
            else{
                sum = arr[i];
                painters += 1;
            }
        }
        
        if(painters  >  k){
            return false;
        }
        
        return true;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        long long low = INT_MAX;
        long long high = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] < low){
                low = arr[i];
            }
            high += arr[i];
        }

        while(low <= high){
            long long mid = (low + high)/2;
            
            if(isPossible(arr,n,k,mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
    
        return low;
    }
};