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

// recursive solution. Shows TLE (198/200 passed)
class Solution {
public:
    int helper(vector<int>& prices, int index, int minSoFar, int n){
        
        if(index == n){
            return 0;
        }
        
        if(prices[index] < minSoFar){
            return helper(prices, index + 1, prices[index],n);
        }
        

        return max(prices[index] - minSoFar + helper(prices, index + 1, INT_MAX, n),
                      helper(prices,index+1,minSoFar,n));
    
        
        
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        int minSoFar = INT_MAX;
        int index = 0;
        int n = prices.size();

        
        return helper(prices, index, minSoFar,n);
        
        
    }
};


class Solution {
public:
    int helper(vector<int>& prices, int index, int minSoFar, int n, unordered_map<int, unordered_map<int,int>>& t){
        
        if(index == n){
            return 0;
        }
        
        if(t.find(index) != t.end()){
            
            unordered_map<int,int> hashMap = t[index];
            if(hashMap.find(minSoFar) != hashMap.end()){
                return t[index][minSoFar];
            }
        }

        if(prices[index] < minSoFar){
            return helper(prices, index + 1, prices[index],n,t);
        }
        

        return t[index][minSoFar] = max(prices[index] - minSoFar + helper(prices, index + 1, INT_MAX, n,t),
                      helper(prices,index+1,minSoFar,n,t));
    
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        int minSoFar = INT_MAX;
        int index = 0;
        int n = prices.size();
        unordered_map<int, unordered_map<int,int>> t; // for memoization
        
        
        return helper(prices, index, minSoFar,n,t);
        
        
    }
};

// or this simple code 
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/208241/Explanation-for-the-dummy-like-me.
int maxProfit(vector<int>& prices) {
        int i = 0, buy, sell, profit = 0, N = prices.size() - 1;
        while (i < N) {
            while (i < N && prices[i + 1] <= prices[i]) i++;
            buy = prices[i];

            while (i < N && prices[i + 1] > prices[i]) i++;
            sell = prices[i];

            profit += sell - buy;
        }
        return profit;
}

// The profit is the sum of sub-profits. Each sub-profit is the difference between selling at day j, and buying at day i 
// (with j > i). The range [i, j] should be chosen so that the sub-profit is maximum:

// sub-profit = prices[j] - prices[i]

// We should choose j that prices[j] is as big as possible, and choose i that prices[i] is as small 
// as possible (of course in their local range).

// Let's say, we have a range [3, 2, 5], we will choose (2,5) instead of (3,5), because 2<3.
// Now, if we add 8 into this range: [3, 2, 5, 8], we will choose (2, 8) instead of (2,5) because 8>5.

// From this observation, from day X, the buying day will be the last continuous day that the price is smallest. 
// Then, the selling day will be the last continuous day that the price is biggest.

// Take another range [3, 2, 5, 8, 1, 9], though 1 is the smallest, but 2 is chosen, because 2 is the smallest in a 
// consecutive decreasing prices starting from 3.
// Similarly, 9 is the biggest, but 8 is chosen, because 8 is the biggest in a consecutive increasing prices starting from 
// 2 (the buying price).
// Actually, the range [3, 2, 5, 8, 1, 9] will be splitted into 2 sub-ranges [3, 2, 5, 8] and [1, 9].

// We come up with the following code above: