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
	    void helper(string S, int n, vector<string>& ans, string temp){
	        if(temp.size() == n){
	            ans.push_back(temp);
	            return;
	        }   
	        
	        
	        for(int i = 0; i < S.length(); i++){
	            temp.push_back(S[i]);
	            string newS = S.substr(0,i) + S.substr(i+1);
	            helper(newS,n,ans,temp);
	            temp.pop_back();
	        }
	    }
	    
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    int n = S.length();
		    vector<string> ans;
		    string temp = "";
		    helper(S,n,ans,temp);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};