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

// given an array
// arr [3 0 0 2 0 4]
// so the values of the array represent the height of the building
// so the question is that in the case of rain, where all the water will get filled
// return the volume (area) of that water

// so we will calculate the height of water above each bulding
// multiply it by 1(the width) and you shall get the area

// so for each building we will find the maximum value to the left and maximum value to the right (not NGL and NGR)
// and height of water above each building would be minimum of max_left and max_right - height of building
// calculating max_left and max_rigt is fairly simple
// no need of stacks
// sum up the heiht of water above each building and you will get the answer

// THIS IS NOT A STACK QUESTION!!!
// This does take some space, basically of order o(2n) as we are taking two arrays

// there is a two pointer approach below
// given by striver
// logic is same
// just that we take O(1) space


class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();

        vector<int> maxLeft(n);
        vector<int> maxRight(n);

        // finding max to left of all elements
        int maxLeftSoFar = 0;
        for(int i = 0; i < n; i++){

            maxLeft[i] = maxLeftSoFar;

            if(height[i] > maxLeftSoFar){
                maxLeftSoFar = height[i];
            }
        }

        // finding max to right of all elements
        int maxRightSoFar = 0;
        for(int i = n-1; i >= 0; i--){
            maxRight[i] = maxRightSoFar;
            
            if(height[i] > maxRightSoFar){
                maxRightSoFar = height[i];
            }
        }

        // reusing maxRight to store minimum of maxleft and maxright
        for(int i = 0; i < n; i++){
            maxRight[i] = min(maxLeft[i], maxRight[i]);
        }

        int area = 0;

        for(int i = 0; i < n; i++){
            if(maxRight[i] - height[i] > 0){
                area += maxRight[i] - height[i];
            }
        }

        return area;

    }
};

// Two pointer approach

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size(); 
        // starting the two pointers
        int left=0; 
        int right=n-1;
        // will store the result
        int res=0;

        // initiallizg max to left and max to right 
        int maxleft=0, maxright=0;
        

        while(left<=right){
            
            // if left ki height is smaller than right ki height
            // the amount of water will only dpened on max to left 
            if(height[left]<=height[right]){

                if(height[left]>=maxleft) 
                {
                    maxleft=height[left];
                }

                else{
                    res+=maxleft-height[left];
                } 
                
                left++;
            }
            else{

                if(height[right]>=maxright){
                    maxright= height[right];
                } 
                else{
                    res+=maxright-height[right];
                } 
                
                right--;
            }
        }
        return res;
    }
};