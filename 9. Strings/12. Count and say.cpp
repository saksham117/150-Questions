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

class Solution {
public:
    string countAndSay(int n) {
        // intializing the output string
        string output = "1";
        
        // handling the base case
        if(n==1)
        {
            return output;
        }
        
        int m = 2;
        
        // iterating for n iterations
        while(m <= n)
        {   
            // 2 pointers to keep track of common characters
            int i = 0; 
            int j = 0;
            char var; // character we are currnetly on
            int count = 0; // its count
            string temp = ""; // this will store the string after mth iteration


            for(; i < output.length(); i++)
            {   
                j = i+1; // j is intialliy just ahead of i

                // intializing these values
                var = output[i];
                count = 1;

                // counting till value remains the same
                if(j < output.length() && output[i] == output[j])
                {   
                    while(j < output.length() && output[i] == output[j])
                    {
                        count+=1;
                        j+=1;
                    }
                    i = j-1; // j-1 will be the last index where ouptu[i] = char var
                    // we did i-1 as due to for loop, i will be incremented
                }

                temp.append(to_string(count) + var);
            }
            output = temp;
            m++;
        }
        return output;
    }
};