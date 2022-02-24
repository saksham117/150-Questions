// good solution
// very good question


// we would be given a coin array, let say [1,2,3]
// and along with that a sum

// now out of the total numver of ways of getting the sum equal to sum, in which way do we require the minimum number of coins

// it is again a problem of unbounded knapsack
// now the coin array is equivalent to weight array and sum is equal to capacity
// t would be t[n+1][sum +1] where n is total number of coins
// see a small example to see

// array = {3,4,5}
// sum  = 4

// now comes the part of initialization
// lets us take the first row wxcluiding t[0][0]
// it states that the number of coins are 0, and the sum should be 1,2,3 .. so on
// so this is not possible
// so since the problem involves finding out the minimum, we initilaize it with INT_MAX - 1,() to avoid overflow later on) (not -1, 
// otherwise that would be the lowest)

// in cases where we do not find solution our answer is INT_MAX-1,
// had we taken INT_MAX and then added 1 to it,
// it would have casued overflow
// that is why we took -1


// now coulmn 1 including t[0][0] can be initiliazed by settting it to 0, because zero coins are required to make the sum 0, 
// given any numer of coins


// now the filling part remians the same

// if we do not find such an element, then return -1

// now it is unbounded knapsack, so we can take the element any number of times
// but if we do take it then we would have to increment the count by 1
// and select the minimum option from either selecting an element or not selecting an element

// or we can say that code differnce from unbounded knapsack is

// 1)initilization is different
// 2) we find minimum
// 3) and when we select the element we add 1
    
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
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        int** dp = new int*[n+1];

        for(int i = 0; i <= n; i++){
            dp[i] = new int[amount+1];
            for(int j = 0; j <= amount; j++){
                if(j == 0){
                    dp[i][j] = 0;
                }
                else if(i == 0){
                    dp[i][j] = INT_MAX - 1;
                }
                else{
                    dp[i][j] = -1;
                }
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(1 + dp[i][j - coins[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        if(dp[n][amount] == INT_MAX - 1){
            return -1;
        }
        return dp[n][amount];
        
    }
};
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
