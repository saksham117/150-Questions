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

// valid appraoch but results in TLE
// we need to optimize this and reduce number of recursive calls
class Solution {
public:
    string helper(int n){
        
        if(n == 1){
            return "0";
        }
        
        string smallAns = helper(n-1);
        string ans = "";
        
        for(int i = 0; i < smallAns.length(); i++){
            if(smallAns[i] == '0'){
                ans.append("01");
            }
            else if(smallAns[i] == '1'){
                ans.append("10");
            }
        }
        
        return ans;
    }
    
    int kthGrammar(int n, int k) {
        
        string ans = helper(n);
        return (ans[k-1] - '0');
    }
};


// This question is based on observation skilss
// 1) we know that to get smaller input we can reduce n by 1
// But the heart of the problem lies in how can we reduce k

// That we need to see 

// So another observation 
// - Size of string increases ny 2 everytime we increase the row number by 1
// - First half of nth row is same as string of row n-1
// n = 3 = 0 1 1 0
// n= 4 =  0 1 1 0 1 0 0 1  

// Second observaton: Later half is complement of bits in first half : 1 ka 0 and 0 ka 1

// So if we need to find kth bit in nth row, then
// 1) if K is less than or equal to middle of length of nth row, then it is same as index in row N-1 (ie solve(n-1, k))
// 2) If not 1, then K = ! of bit at position index - middle, so in this case call will be  !solve(n-1, k - middle)

// so this is the beautiful peice of code
class Solution {
public:
    int kthGrammar(int n, int k) {
        
//         base case
        if(n == 1 && k == 1){
            return 0;
        }
        
//         length of string in nth row is 2^(n-1)
        int length = 1<<(n-1);
        int middle = length/2;
        
        if(k <= middle){
            return kthGrammar(n-1,k);
        }
        else{
            return !kthGrammar(n-1, k - middle);
        }
        
    }
};