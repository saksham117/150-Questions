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

// ditto same code as previous question
// yahan par yeh hai ki we will be given n
// we need to genarte all binary strings of size n such that
// all prefixes of that n bit string follow the property that number of 1s are greater than number of zeros  
// that is the meaning of the question

class Solution{
public:	
    void helper(vector<string>& ans, int n, string str, int count){
        
        if(str.length() == n){
            ans.push_back(str);
            return;
        }
        
        helper(ans,n,str + '1', count + 1);
        
        if(count >= 1){
            helper(ans,n,str + '0', count - 1);
        }
        
        return;
    }
    
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    int count = 0;
	    string str = "";
	    vector<string> ans;
	    
	    helper(ans,N,str,count);
	    return ans;
	}
};