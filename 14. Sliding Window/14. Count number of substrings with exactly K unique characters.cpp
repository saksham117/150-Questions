// Based on the previous problem
// But has additional steps
// we need to find both
// count of subtrings with atmostK and count of substrings with atmost(k-1)
// and then subtract their answers
// that will then be the answer

// this fails on gfg
// i guess they have fucked up their IDE
// coz same approach works on leetcode
// where instead of string we are given an array
// https://leetcode.com/discuss/interview-question/370157

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

class Solution {
public:
    int solution(vector<int>& num, int k) {
	// write your code here
    int i = 0, j = 0;
    int count = 0;
    unordered_map<int, int> freqMap;

    int n = num.size();

    while(j < n){

        freqMap[num[j]]++;

        if(freqMap.size() <= k){
            j++;
        }
        else if(freqMap.size() > k){
            while(freqMap.size() > k){

                count += j-i;
                freqMap[num[i]]--;

                if(freqMap[num[i]] == 0){
                    freqMap.erase(num[i]);
                }

                i++;
            }

            j++;
        }
    }

    int m = j-i;
    int last = (m*(m+1))/2;
    count += last; // this is when j becomes greater than n and there is still i 
    // to jitne remaining hai
    // unke kitne combination ban sakte hain
    // yeh voh hai
    // baiscally pehle elemet in sab main would be taken m times, agla m-1 times and so on 
    // take examples and you shall see why
    
    return count;

}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solution(nums,k) - solution(nums,k-1);
    }
};