// An efficient solution is to use Greedy approach. The basic idea of the greedy approach is to calculate the 
// ratio value/weight for each item and sort the item on basis of this ratio.

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

struct Item{
    int value;
    int weight;
};

struct Temp{

    double ratio;
    int value;
    int weight;
}; 

class Solution
{
    public:
    
    static bool compare(Temp a, Temp b)
    {
        return (a.ratio > b.ratio);
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        Temp *array = new Temp[n];

        for(int i = 0; i < n; i++)
        {
            double r = (double) arr[i].value / (double) arr[i].weight;

            struct Temp t1;
            t1.ratio = r;
            t1.value = arr[i].value;
            t1.weight = arr[i].weight;

            array[i] = t1;

        }

        sort(array, array + n, compare);
        double profit = 0;

        for(int i = 0; i < n; i++)
        {
            if(W == 0)
            {
                break;
            }

            int w1 = array[i].weight;
            if(w1 <= W)
            {
                profit += array[i].value;
                W = W - array[i].weight;
            }
            else
            {
                profit = profit + (array[i].ratio * W);
                W = 0;
            }
        }

        return profit;

    }
        
};