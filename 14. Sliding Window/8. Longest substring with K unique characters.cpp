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
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char,int> freqMap;
        int i = 0;
        int j = 0;
        int N = s.length();
        
        int maxLen = -1;
        
        while(j < N){
            
            // performing the calculation
            if(freqMap.find(s[j]) == freqMap.end()){
                freqMap[s[j]] = 1;
            }
            else{
                freqMap[s[j]] += 1;
            }
            
            // first case
            if(freqMap.size() < k){
                j++;
            }
            // second case
            else if(freqMap.size() == k){
                // cout<<maxLen<<'\n';
                maxLen = max(maxLen, j-i+1); // had to do this
                // for some weird reason, using if I was getting spurious results
                // cout<<i<<" "<<j<<" "<<maxLen<<'\n';
                j++;
            }
            else if(freqMap.size() > k){
                
                while(freqMap.size() > k){
                    if(freqMap[s[i]] == 1){
                        freqMap[s[i]] = 0;
                        freqMap.erase(s[i]);
                    }
                    else{
                        freqMap[s[i]] -= 1;
                    }
                
                    i++;
                }
                
                j++;
            }
        }
        
        return maxLen;
    }
};