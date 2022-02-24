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
    vector<vector<int>> threeSum(vector<int>& num) {

        // result array
        // we didnt use a set as interviewer may or may not like that and would want us to handle duplicates ourselves  
        vector<vector<int> > res;
        
        //base case 
        if (num.empty())
            return res;

        int n = num.size(); 
        // this step is necessary for us to be able to aplly left and right pointer logic
        sort(num.begin(),num.end());

        // making i move from 0 to n-1
        for (int j = 0; j < n; j++) {
        
            int target = 0 - num[j]; // calculating intermediate sum
            
            // moving j from i+1 to n
        
            
                int front = j + 1; // intializing first and last(left and right pointers)
                int back = n - 1;
            
                while(front < back) { // = also not included as it would point to a single element
                
                    int two_sum = num[front] + num[back]; // calculate the sum 
                
                    if (two_sum < target) front++; // if less
                
                    else if (two_sum > target) back--; // if more
                
                    else {
                        
                        // vector of size 4 intiallized with 0
                        vector<int> triplet(3, 0);
                        triplet[0] = num[j];
                        triplet[1] = num[front];
                        triplet[2] = num[back];
                        res.push_back(triplet);
                    
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == triplet[1]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == triplet[2]) --back;

                        // can be further optimized as currently we are only moving the duplicates once the solution has been found
                        // if not found with one element even then we need to move forward or backwards
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < n && num[j + 1] == num[j]) ++j;
            }

        return res;        
    }
};


        
        
        