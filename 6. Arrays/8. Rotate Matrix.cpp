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

// newer version
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        // taking trasnpose
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // swapping the rows
        int i = 0;
        int j = m -1;

        while(i < j){
            for(int k = 0; k < n; k++){
                swap(matrix[k][i], matrix[k][j]);
            }

            i+=1;
            j-=1;
        }
        
    }
};
class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        
        // take transpose of the matrix
        
        int n = arr.size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if(i == j)
                {
                    continue;
                }
                else
                {
                    swap(arr[i][j], arr[j][i]);
                }
            }
        }
        
        
        // swapping first and last rows
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n/2; j++)
            {
                swap(arr[i][j], arr[i][n-j-1]);
            }
        }
    }
};

