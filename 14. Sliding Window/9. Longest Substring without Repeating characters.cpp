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
    int lengthOfLongestSubstring(string s) {
        
        int i = 0, j = 0;
        int maxLen = 0;
        int n = s.length();
        unordered_map<char, int> freqMap;
        bool flag = false; // setting flag to true as soon as I encounter a repeating character
        
        while(j < n){
            
//             performing the calculation
            if(freqMap.find(s[j]) == freqMap.end())
            {
                freqMap[s[j]] = 1;
            }
            else{
                freqMap[s[j]] += 1;  
                flag = true;
            }
//             checking the condition
            if(flag == true){
                while(freqMap[s[j]] != 1){
                    freqMap[s[i]] -= 1;
                    i++;
                }
                
                flag = false;
            }
            
//             no repeating characters
            if(flag == false){
                maxLen = max(maxLen, j-i +1);
            }
            
            j++;
            
        }
        
        return maxLen;
    }
};