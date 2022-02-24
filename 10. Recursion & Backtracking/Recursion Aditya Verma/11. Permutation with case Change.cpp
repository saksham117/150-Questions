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

// same concept as previosu question 
// we just need to see what alll choices we have and then code accordingly 


class Solution {
public:
    void helper(vector<string>& ans, string str, int i){
        
        // base case
        if(i == str.length()){
            ans.push_back(str);
            return;
        }
        
        // if it is a digit, then no need to do anything
        if(isdigit(str[i])){
            helper(ans,str,i+1);
        }
        else{
            
            // if alphabet
            // case1: let it remain as such 
            helper(ans, str, i+1);
            
            // case2 if it is uppercase, convert to lowercase
            if(str[i] >= 65 && str[i] <= 90){
                
                str[i] = str[i] + 32;
                helper(ans,str,i+1);
                str[i] = str[i] - 32;
            }
            else{ // else if it is lowercase, convert to uppercase
                str[i] = str[i] - 32;
                helper(ans,str,i+1);
                str[i] = str[i] + 32;
            }
        }
        
        return;
    }
    
    
    vector<string> letterCasePermutation(string s) {
        int index = 0;
        string str = "";
        vector<string> ans;
        helper(ans,s,index);
        return ans;
    }
};