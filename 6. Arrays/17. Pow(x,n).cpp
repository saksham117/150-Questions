// We need to calculate power of x^n
// We cannot make use of the power function made availabe to us
// and we need to give the answer upto 5 decimal places

// Brute force
// run a for loop from 1 to n, and multipy x that many number of times

// If n can be negative, then whatever x^n returns, return 1/x^n

// Edge cases
// Take care when 
// 1) x == 0
// 2) n == 0
// 3) Note that range of int is from -2,147,483,648 to 2,147,483,647. One less on the positive side
// So if we are given to calculate x^-2,147,483,648 and we first calculate x^2,147,483,648, it will give us overflow
// So for that use long or double or long long.

// So time complexity is O(N) and space is O(1)

// Optimized Approach
// Say we need to calculate 2^10
// this is same as (2^2)^5
// so this becomes 4^5
// Now since power is odd, we will take one 4 outside
// and write it as 4 X 4^4
// now 4^4 is nothing but (4X4)^2
// so now we have 4 X (16)^2
// further reduced to 4 X (16X16)^1
// now no further breaking down. Just multiply the remaining terms

// So these are the case
// 1) if n%2 == 0
    // x = x mutlipied x
    // n = n/2

// 2) if n%2 == 1
    // ans = ans mutlipied x
    //  n = n - 1


// Its time complexity is log2(N)
// becasue everytime we are at even, we divide power by 2
// and if its odd, in next step we make it even

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
    double myPow(double x, int n) {
        
        // handling the two edge cases
        if(n == 0){
            return 1;
        }
        else if(x == 0){
            return 0;
        }

        // ans will be double
        double ans = 1;
        // initially assuming power to be +ve and taking long long to avoid overflow
        long long power = abs(n);

        // applying the logic
        while (power > 1){
            if(power%2 == 0){
                x = x*x;
                power = power/2;
            }
            else{
                ans = ans*x;
                power = power - 1;
            }
        }
        
        // once i exit the loop, multiply present x with present ans to get final ans
        ans = ans*x;

        // if n was negative else if it was positive
        if(n < 0){
            return 1.0/ans;
        }
        else{
            return ans;
        }

    }
}; 