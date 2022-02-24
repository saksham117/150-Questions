// we are given a rod and it s lenght N/L
// so there are a large number of ways in which we can divide the rod into smaller parts like
// if n = 8
// divisions can be 3,5 or 3,3,2 or 1,7 or 6,2 and so on

// we will be given two arrays
// price and length
// if we select a length, we select a proce assocaited with it

// so let us say lenght array is len [1,2,3,4,5,6,7,8]
// and price array is          price [1,5,8,9,10,17,17,20]

// so if we make division 6 and 2
// then price will be 17 + 5 = 22
// and we just need to maximize this profit

// someties we are not given the length array, because it is understoid that the first element of price array is for len = 1 
// and last element of price array is for len = 8

// so in that case, we can even make the length array on our own
// it will be of size n and we are gonna fill 1,2,3,4,5,6,7,8

// so in input we have n, length array and price array
// this is similar to knapsack where we are given W, weight and value array

// so n correspond to W, price to val and length to weight

// now we know it is a knapsack
// now 0-1 or unbounded knapsack
// since after cutting the rod we can select the piece again, therefore this becomes a problem of unbounded knapsack


// so the code is exactly same as the unbounded knapascak
// only change is that weight array becomes lenght array and value array becomes price array
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
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int** dp = new int*[n+1];
        for(int i = 0; i <= n; i++){
            dp[i] = new int[n+1];
            for(int j= 0; j <= n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = -1;
                }
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++)
            {
                if(i <= j){
                    dp[i][j] = max(price[i-1] + dp[i][j - i], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][n];
    }
};