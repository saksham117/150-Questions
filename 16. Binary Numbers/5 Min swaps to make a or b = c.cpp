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


// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/discuss/488292/THE-MOST-SIMPLE-SOLUTION(if-you-know-a-few-bitman-tricks)
// Fab approach

// I saw a lot of posts for this question and realized mine was easier to understand and was simple.
// Intuition:

// Check every bit of a and b and compare it with c
// Example 1:
// 0010->a(2) 0110->b(6) 0101->c(5)

// Compare 0,0 and 1(LSBs of the 3 numbers)
// We see that atleast one of the bits of a and b(0 and 0) must be flipped to 1 for the result to be c,so we i
// ncrement the count value by one.

// We get the LSB of a number by performing AND operation of that number with one.
// Eg: 3->0011
// 3 AND 1 -> 0011 & 0001 which is equal to 1 which means LSB is one , similarly result will be zero if LSB is zero.

// How do we go to the next bit?
// Use unsigned right shift operator(>>>),this operator shifts the bits one to the right.

class Solution {
    public int minFlips(int a, int b, int c) {
        if((a|b)==c)
            return 0;
        
        int flips=0;
        
        while(c!=0 || a!=0 || b!=0 ) //compare bits of the numbers as long as atleast one of them is nonzero
        {
            if((c&1)==1)
            {
                if((a&1)==0 && (b&1)==0) //if both are zero while c is 1,one flip is needed
                    flips+=1;
                
            }
            
            else if((c&1)==0)
            {
                if((a&1)==1 && (b&1)==1) //if both are one while c is zero,we need to change both the bits to zero to get the result .So,this requires 2 flips.
                    flips+=2;
                
                else if((a&1)==1 || (b&1)==1) //if one of the bits is one while c is zero,we need to flip it once.
                    flips+=1;
                
            }
            a>>>=1; //moving through the bits
            b>>>=1;
            c>>>=1;
        }
       return flips;
    }
    
    
}