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

// Say the given array is:

// [7, 1, 5, 3, 6, 4]

// If we plot the numbers of the given array on a graph, we get:
// https://leetcode.com/media/original_images/121_profit_graph.png

// The points of interest are the peaks and valleys in the given graph. We need to find the largest peak following the 
// smallest valley. We can maintain two variables - minprice and maxprofit corresponding to the smallest valley 
// and maximum profit (maximum difference between selling price and minprice) obtained so far respectively.

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
        
    }
};