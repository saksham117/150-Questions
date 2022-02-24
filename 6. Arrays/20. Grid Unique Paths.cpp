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


// Brute force solution is a recursive solution, wherein you are gonna try out all the paths
// That is given below
class Solution {
public:
int countPaths(int i, int j, int n, int m){
    if(i == (n-1) && j == (m-1))
    {
        return 1;
    }

    if(i >= n || j >= m){
        return 0;
    }
    else {
        return countPaths(i+1, j,n,m) + countPaths(i, j + 1,n,m);
    }


}
    int uniquePaths(int m, int n) {
            int i = 0;
            int j = 0;
            return countPaths(0,0,m,n);
    }
};

// writing dp code from this is easy
// aditya verma taught well
// just intialization was wrong, base case main return 1
// and recursive main right ya down jaa rahe
// yahan fill karne ke liye socha ki given cell ki value will depend on ki yahan kaise pahunch jaa sakta tha
// ya to iske just left element se ya just up element se
// and that is the logic

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0 || n==0)
        {
            return 0;
        }
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
            dp[i][0]=1;
        }
         for(int i=0;i<n;i++)
        {
            dp[0][i]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};


// optimal solution using combinatorics
// number of right steps will always be m -1 (ie no of cols -1)
// number of down steps will always be n -1 (ie no of rows -1)
// so total number of steps to be taken would be (m-1) to right and n- 1 down
// so total steps = m + n - 2 :  ((m-1) + (n-1))

// so if in these m+n-2 steps I am able to choose(select) my m-1 right step
// or my n-1 down steps, then remainng places will be placed by dow or right steps respectively
// so now we need to find that


class Solution {
public:
    int uniquePaths(int n, int m) {
            // finding right steps
            int N = n + m - 2;
            int r = n - 1; 
            double res = 1;
            // code for nCr : basically doing (n+m-2)C(n-1)
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }
};