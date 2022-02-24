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

class Solution
{
	public:
	    void helper(string S, string permutation, vector<string>& ans){
	        
	        if(S.length() == 0){
	            ans.push_back(permutation);
	            return;
	        }
	        
	        for(int i = 0; i < S.length(); i++){
	            string newS = S.substr(0,i) + S.substr(i+1);
	            helper(newS,permutation + S[i], ans);
	        }
	        
	        return;
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    string permutation = "";
		    vector<string> ans;
		    helper(S,permutation,ans);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};