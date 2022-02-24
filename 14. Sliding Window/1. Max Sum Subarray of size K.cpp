#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<set>
#include<map>

using namespace std;


class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int maxSum = 0;
        int sum = 0;
        
        for(int i = 0; i < K; i++){
            sum += Arr[i];
        }
        
        maxSum = sum;
        
        for(int i = K; i < N; i++){
            sum = sum - Arr[i-K] + Arr[i];
            if(sum > maxSum){
                maxSum = sum;
            }
        }
        
        return maxSum;
    }
};

// another approach of defining windows that can be generalized
// take i and j as zero
// while j-i+1 < k
// keep on incrementing j only
// when j-i+1 == k
// move i and j together by 1

// this will be the standard algo
// addition jhar baar karo
// and deletion apne output obtain karne baad karo
// and when to move i and when to move j
// vo to pata hi hai

class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int maxSum = 0;
        int sum = 0;
        int i = 0;
        int j = 0;

        while(j < N){
            sum+=Arr[j];
            if(j-i+1 < K){
                j++;
            }
            else if(j-i+1 == K){

                if(sum > maxSum)
                {
                    maxSum = sum; 
                }

                sum = sum - Arr[i];
                i++;
                j++;
            }
        }
        
        return maxSum;
    }
};