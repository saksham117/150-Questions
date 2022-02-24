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

// Actually not a permutation question
// But very similar ot concept used in generating all subsets for a given array
// Same concept ki space daalein ya na, is being used here

class Solution{
public:
    
    void helper(string S, vector<string>& ans, int index){
        
        if(index == S.length() - 1){
            ans.push_back(S);
            return;
        }
        
        S.insert(index+1, " ");
        helper(S,ans,index+2);
        S.erase(index+1, 1);
        helper(S,ans, index+1);
        return;
    }
    
    vector<string> permutation(string S){
        // Code Here
        int index = 0;
        vector<string> ans;
        
        helper(S,ans,index);
        return ans;
        
    }
};