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


// These problems are not simple at all
using namespace std;

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        if(A.length() == 0){
            return 1;
        }

        for(int i = 0; i < B.size(); i++){
            if(A == B[i]){
                return 1;
            }
        }

        for(int i = 0; i < A.size() - 1; i++){

            int ans = wordBreak(A.substr(0, i+1), B) && wordBreak(A.substr(i+1), B);

            if(ans){
                return ans;
            }
        }

        return 0;


    }
};

// optimizing it 
class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        if(A.length() == 0){
            return 1;
        }

        for(int i = 0; i < B.size(); i++){
            if(A == B[i]){
                return 1;
            }
        }

        for(int i = 0; i < A.size() - 1; i++){

            string s1 = A.substr(0, i+1);
            string s2 = A.substr(i+1);

            int left = 0;
            int right = 0;

            for(int i = 0; i < B.size(); i++){
                if(s1 == B[i]){
                    left = 1;
                }
            }

            if(left == 0){
                left = wordBreak(A.substr(0, i+1), B);
            }

            if(left){
                for(int i = 0; i < B.size(); i++){
                    if(s2 == B[i]){
                        right = 1;
                    }
                }

                if(right == 0){
                    right = wordBreak(A.substr(i+1), B);
                }

                int ans =  left && right;

                if(ans){
                    return ans;
                }
            }
            
        }

        return 0;


    }
};

// Howvere this is the approach that works on gfg
// difference from above is to not go and recursively calculate for s1
// if s1 not in dictionary, do not check for s2 
// Pepcoding also did this way only
// https://www.youtube.com/watch?v=LmHWIsBQBU4
// This approach is also helpful when we need to print thr actual way in which we have broken it

int wordBreak(string A, vector<string> &B) {
    //code here
    if(A.length() == 0)
    {
        return 1;
    }
    
    for(int i = 0; i < A.length(); i++)
    {
        string s1 = A.substr(0, i+1);
        string s2 = A.substr(i+1);

        if(find(B.begin(), B.end(),s1) != B.end())
        {   
            int ans = 0;
            if(s2 == "")
            {
                ans = 1;
                return ans;
            }

            else
            {
                ans = wordBreak(s2,B);
                if(ans == 1)
                {
                    return ans;
                }
            }

        }
    }

    return 0;
}