// create an array of size equal to size of string and let us assign meaning to it 
// index i in array will represent ki how many number of strings can be made from substring 
// which goes from(0  to  i)
// to find that we will break that substr into all possible substring further
// like pep can be broken as pep, p-ep, pe-p

// we are solving an advanced level question
// each index stores the count whereas in question we just need true/false
// so by doing this, we are covering both questions

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



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int*dp = new int[s.length()];
        for(int i = 0; i < s.length(); i++){
            dp[i] = 0;
        }

        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j <= i; j++){
                string word2check = s.substr(j, i+ 1 -j);

                for(int k = 0; k < wordDict.size(); k++){
                    if(word2check == wordDict[k]){
                        if(j > 0){
                            dp[i] += dp[j-1]; // word jyust before that
                        }
                        else{
                            dp[i] += 1;
                        }

                        break;
                    }
                }
            }
        }

        return dp[s.length()-1] > 0;
    }
};

