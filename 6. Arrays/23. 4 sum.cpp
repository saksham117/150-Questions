// Naive Approach
// Take 3 pointer i,j,k 
// sort the array
// then find 4th element using binary search 

// for(int i = 0; i < n; i++){
//     for(int j = i+1; j < n; j++){
//         for(int k = j + 1; j < n; j++)

//             sum them up and find target - sum using binary search only on the half of the array after index k
//             /to find unique elememtn store it in an unordered set of type vect<int>
                // time complexity is N^3logN + NlogN of sorting
//     }
// }


// Interviewever wont be happy
// So now new approach
// Sort the array 
// Take two pointers i and j
// take left pointer at j + 1 and right pointer at end of array 
// so we will serach for target - (arr[i] + arr[j]) in between left and right
// and increment and decrement left and right accordingly 
// also we can skip the duplicates to further optimize as in the question itself we are asked unique subsets 

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
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        
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
        for (int i = 0; i < n; i++) {
        
            int target_3 = target - num[i]; // calculating intermediate sum
            
            // moving j from i+1 to n
            for (int j = i + 1; j < n; j++) {
            
                int target_2 = target_3 - num[j]; // sum we want form our left and right pointers
            
                int front = j + 1; // intializing first and last(left and right pointers)
                int back = n - 1;
            
                while(front < back) { // = also not included as it would point to a single element
                
                    int two_sum = num[front] + num[back]; // calculate the sum 
                
                    if (two_sum < target_2) front++; // if less
                
                    else if (two_sum > target_2) back--; // if more
                
                    else {
                        
                        // vector of size 4 intiallized with 0
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) --back;

                        // can be further optimized as currently we are only moving the duplicates once the solution has been found
                        // if not found with one element even then we need to move forward or backwards
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < n && num[j + 1] == num[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < n && num[i + 1] == num[i]) ++i;
        
        }
    
        return res;
    }
};

