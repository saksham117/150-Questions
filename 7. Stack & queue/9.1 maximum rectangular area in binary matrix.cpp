// question is that 
// so this problem uses the concept of mah problem

// mah can be summarized as 

int MAH(int arr[], int n)
{
    // right array -> obtained by finding NSR 
    // left array -> obtained by finding NSL
    // width array _. right array - left array -1
    // area = arr[i] * width[i]
    // return max(area array)

}

// qiestion is given a binary matrix

[0 1 1 0]
[1 1 1 1]
[1 1 1 1]
[1 1 0 0]

// what is the maximum area rectangle in binary matrix
// so I get the solution
// first we will take the first row
// assume 0/1 as height of buildings and obtain an answer of MAH from first array
// then we will go to second array. In this height of building will be 1+ arr[0][i], or 0 if the element in row 2 is itself zero
// then we will apply mah on array2 and similary find max area rectangle under histogram
// ?repeat this process for all rows
// ?max area will be the answer 

// TO DO THIS, FIERST CREATE AN MAH FUNCTION HAING PARAMETER AS THE ARRAY AND N
// AND THEN APPLYING THIS FUNCTION TO EACH ROW OF THE 2-D MATRIX

// Solution of the above algo by some other guy 
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>
#include<map>

using namespace std;

class Solution {
public:
    int largestRectangle(vector<int> &dp)
    {
        stack<int> st;
        st.push(-1);
        int max_area = 0;
        for(int i=0;i<=dp.size();i++)
        {
            int val = (i == dp.size()) ? -1 : dp[i];
            while(st.top() != -1 && dp[st.top()] > val)
            {
                int height = dp[st.top()];
                st.pop();
                int width = i - st.top() - 1;
                max_area = max(max_area,width * height);
            }
            st.push(i);
        }
        return max_area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        //base cases
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        if(n + m == 2) return matrix[0][0] == '1';
        
		//program to calculate maximum height for current element
        vector<int> dp(m,0);
        
        int res = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
				//if current 0 then total height is 0 else increase the previous height
                if(matrix[i][j] == '0') dp[j] = 0;
                else dp[j]++;
            }
            res = max(res,largestRectangle(dp));
        }
        
        return res;
    }
};

