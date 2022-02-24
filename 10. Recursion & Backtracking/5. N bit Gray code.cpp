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


// easy 

// An n-bit gray code sequence is a sequence of 2^n integers where:

    // Every integer is in the inclusive range [0, 2^n - 1],
    // The first integer is 0,
    // An integer appears no more than once in the sequence,
    // The binary representation of every pair of adjacent integers differs by exactly one bit, and
    // The binary representation of the first and last integers differs by exactly one bit.


// Given an integer n, return any valid n-bit gray code sequence.

// Solution
// We can do this recursively
// so if i am given n == 3
// i will ask for gray code of n == 2
// if i am given n == 2, I will return gray code of n == 1
// for n == 1, I know grey code == 0,1


class Solution {
    public:

    vector<string> helper(int n){

        // base case
        if(n == 1){
            vector<string> ans;
            ans.push_back("0");
            ans.push_back("1");
            return ans;
        }

        // call for smaller n
        vector<string> smallAns = helper(n-1);

        // after returning answer
        // append 0 and then append 1(in reverse fashion, otherwise property will be violated of gray code 

        vector<string> finalAns;

        // appending 0
        for(int i = 0; i <smallAns.size(); i++){
            finalAns.push_back("0" + smallAns[i]);
        }

        // appending 1
        for(int i = smallAns.size() - 1; i >= 0; i--){
            finalAns.push_back("1" + smallAns[i]);
        }

        return finalAns; 
    }

    // helper function to convert binary to decimal
    vector<int> BinaryToDecimal(vector<string> binaryCodes){

        vector<int> answer;
        for(int i = 0; i < binaryCodes.size(); i++){

            string code = binaryCodes[i];
            int number = (code[0] - '0');
            for(int i = 1; i < code.size(); i++){
                number = number << 1 | (code[i] - '0');
            }

            answer.push_back(number);

        }
        
        return answer;
    }
    vector<int> grayCode(int n) {

        // getting all the binary codes by calling helper function
        vector<string> binaryCodes = helper(n);
        // converting binary to string and returning the answer (reqd for leetcode)
        return BinaryToDecimal(binaryCodes);
        
    }
};