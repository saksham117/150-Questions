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

// question 1
// NEXT LARGEST ELEMENT (this is the solution for gfg question)

// SO THE QUESTION IS THAT, GIVEN AN ARRAY, WE HAVE TO FIND AN ELEMENT LARGER THAN IT, WHICH IS NEARTEST TO THE GIVEM ELEMENT
// FOR EXAPMLE FOR THE ARRAY
//  [1 3 2 4]
// [3 4 4 -1] THIS WILL BE THE RESULTANT NEXT GREATEST ELEMENT ARR AY

// SO WHAT i WILL DO IS THAT i WILL START from the right most element
// for that the answer will alwasy be -1
// and then push that element into stack as well
// now i would traverse to the left
// if the element is greater than element at top of stack
    // then keep on popping the stack till a larger element than it is found
    //  if found, that is the largest element to the right and also push the element into the stack
        // else if stack becomes empty, make the answeer as -1 and push the element into the stack
//  if element is smaller
//  then answer is top of stack and also push this element to top of stack

class Solution{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> s;
        vector<long long> output;

        output.push_back(-1);
        s.push(arr[n-1]);
        
        for(int i = n-2; i >= 0; i--)
        {
            if(arr[i] <= s.top())
            {
                output.push_back(s.top());
                s.push(arr[i]);
            }
            else
            {
                while(!s.empty())
                {
                    
                    if(s.top() >= arr[i])
                    {
                        output.push_back(s.top());
                        s.push(arr[i]);
                        break;
                    }
                    s.pop();
                }

                if(s.empty())
                {
                    output.push_back(-1);
                    s.push(arr[i]);
                }
            }
        }


        // reverse the array and then return
        reverse(output.begin(),output.end());
        return output;
    }
};

int main()
{
   


    return 0;
}


class Solution {
public:

    vector<int> helper(vector<int> nums, int n){

        stack<int> s;
        vector<int> output;

        output.insert(output.begin(), -1);   
        s.push(nums[n-1]);
        
        for(int i = n-2; i >= 0; i--)
        {
            if(nums[i] <= s.top())
            {
                output.insert(output.begin(), s.top());
                s.push(nums[i]);
            }
            else
            {
                while(!s.empty())
                {
                    
                    if(s.top() >= nums[i])
                    {
                        output.insert(output.begin(), s.top());    
                        s.push(nums[i]);
                        break;
                    }
                    s.pop();
                }

                if(s.empty())
                {
                    output.insert(output.begin(), -1);    
                    s.push(nums[i]);
                }
            }
        }
        return output;

    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> temp = helper(nums2, nums2.size());
        vector<int> output; 

        unordered_map<int, int> mapping; 
        for(int i = 0; i < nums2.size(); i++){
            mapping[nums2[i]] = temp[i];
        }

        for(int i = 0; i < nums1.size(); i++){
            output.push_back(mapping[nums1[i]]);
        }

        return output;
    }
};