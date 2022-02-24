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
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    if(n <= 0){
	        return 0;
	    }
	    
	    if(n == 1){
	        return arr[0];
	    }
	    
	    return max(arr[n-1] + findMaxSum(arr, n-2), findMaxSum(arr, n-1));
	}
};

// dp code using above logic
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    int* dp = new int[n+1];
        dp[0] = 0;
        dp[1] = arr[0];

        for(int i = 2; i <= n; i++){
            dp[i] = max(arr[i-1] + dp[i-2], dp[i-1]);
        }

        return dp[n];
	}
};


// withouts extra space solution
//c++ program for the above approach



/*Function to return max sum such that no two elements
are adjacent */
int FindMaxSum(vector<int> arr, int n)
{
	int incl = arr[0];
	int excl = 0;
	int excl_new;
	int i;

	for (i = 1; i < n; i++)
	{
		/* current max excluding i */
		excl_new = (incl > excl) ? incl : excl;

		/* current max including i */
		incl = excl + arr[i];
		excl = excl_new;
	}

	/* return max of incl and excl */
	return ((incl > excl) ? incl : excl);
}

// Driver program to test above functions
int main()
{
	vector<int> arr = {5, 5, 10, 100, 10, 5};
	cout<<FindMaxSum(arr, arr.size());
}
