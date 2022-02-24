// Brute force
// Calculate factorial of n simply and then to find number of trailing zeros just continue dividing by 10 till you have remainder as 0 
// problem: Buffer overflow 

// optimal approach

// We get a trailing zero when we multiply by 10 

// so if we are able to count the number of pairs of 2x5 we will get the number of trailing zeros
// whats even better is that we just need to find the number of 5's in the factorial
// as number of 5s will always be less than number 0f 2s
// so for a 5 we will always have a 2 

// so what we need is 5^y * k = n!
// where we need to find y

// so one way is to simply find the floor of n/5 
// but we are not done here
//  for a factorial like 28! we also have 25 in it, and 25 returns two 5s
// similarly 125 will return three 5s

class Solution
{
public:
    int trailingZeroes(int N)
    {
        // Write Your Code here
        int count = 0;
        
        for(int i = 5; i <= N; i = i*5){
            count += N/i;
        }
        
        return count;
        
    }
};

