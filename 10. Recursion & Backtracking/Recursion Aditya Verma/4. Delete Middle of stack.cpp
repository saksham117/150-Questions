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
    //Function to delete middle element of a stack.
    void helper(stack<int>& s, int middle){
        
        if(middle == 0){
            s.pop();
            return;
        }    
    
        int top = s.top();
        s.pop();
        helper(s,middle-1);
        s.push(top);
        return;
    }
    
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        int middle = sizeOfStack/2;
        
        helper(s,middle);
    }
};
