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

// again looks like a tough question but really is not
// again based on the same concept of what all choice do I have at the given instance
// similar to subcase generation as well as the previosu 2 questions I did 

// Aditya verma is really very very good
// aisa thought process baith jaata
// ki jo problem pehle nahi ho rahi thi
// ab chutkiyon main ho rahi hai!!
// just like that

class Solution {
public:
    void helper(vector<string>& output, int n, string str, int total, int opening){
        
        if(total == n){
            while(opening > 0){
                str += ')';
                opening--;
            }
            
            output.push_back(str);
            return;
        }
        
        helper(output, n, str + '(', total + 1, opening + 1);
        
        if(opening > 0){
            helper(output, n, str + ')', total, opening - 1);
        }
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        int total = 0;
        int opening = 0;
        string str;
        
        helper(output,n,str, total, opening);
        
        return output;
    }
};