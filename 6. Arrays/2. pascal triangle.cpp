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
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> triangle; 

        vector<int> temp(1);
        temp[0] = 1; 
        triangle.push_back(temp);

        for(int i = 2; i <= numRows; i++){
            vector<int> temp(i);

            for(int j = 0; j < i; j++){
                if(j == 0){
                    temp[j] = 1;
                }
                else if(j == i-1){
                    temp[j] = 1;
                }
                else{
                    temp[j] = triangle[i-2][j-1] + triangle[i-2][j];
                }
            }

            triangle.push_back(temp);
        } 

        return triangle;
    }
};

// Two Related Problems!!!
// If just asked to print a row, we can print nCr, where n is row number and r varies from 0 to n
// If just asked to print particular element, then we can just return nCr

// Code for nCr

int binomial(int N, int r){
    double res = 1;
    // code for nCr : basically doing (n+m-2)C(n-1)
    for (int i = 1; i <= r; i++){
        res = res * (N - r + i) / i;
    }
    
    return (int)res;
}


