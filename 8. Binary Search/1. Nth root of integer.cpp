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

// You are given 2 numbers (n , m); the task is to find n√m (nth root of m).

// We will use binary search over here!
// Binary search can be applied to any search space which is monotonic (linearly increasing or linearly decreasing) in nature

// So once we have deduced that binary search can be applied, next we have to deduce the search space
// ie, where can our answer lie?


// if we are calculating 3rd root of 27, ie N = 3 and M = 27
// then my answer will lie between 1 and 27
// so assign low to 1 and high to 27, and then we simply apply binary search

// so calculate mid as before. See if arr[mid] X arr[mid] X arr[mid] == M.
// We multipled 3 times because N = 3. So in general we will multiply N times.

// if arr[middle]^N == M, stop and return. This case generally does not occur
// else if smaller then low = mid (not mid+1)
// else high = mid(not mid -1)

// instead of int, we will be using float or double

// we are gonna keep on searching, till our high-low > 10^-6. This is when answer was asked upto 5 decimal places
// if it had been asked till 8 decimal places, we would have searched till high-low > 10^-9

// Also note e, that is 10^ something is a valid keyword in C++


double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

double getNthRoot(int n, int m) {
    // defining our search space
    double low = 1;
    double high = m;

    double eps = 1e-6; 
    
    while((high - low) > eps) { // we are gonna keep on searching, till our high-low > 10^-6.

        // calculating mid as before
        double mid = (low + high) / 2.0;

        // applying binary search 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    
    cout << low << " " << high << endl; //we can print/return any of high or low as both will be same and only differ at 6th decimal place
    
    // just to check
    cout << pow(m, (double)(1.0/(double)n)); 
}

// Time complexity
// our search space is not exactly m numbers
// for each number in m, we go from 1.00000 to 1.99999
// so in actual, we have 10^5 X M numbers where we search. The 5 because we are searching upto 5 decimal places
// so binary search will take log2(mX10^5)
// and we are also running a multiplier, which runs for n times

// so time complexity is NXlog(MX10^d), where d is number of decimal places