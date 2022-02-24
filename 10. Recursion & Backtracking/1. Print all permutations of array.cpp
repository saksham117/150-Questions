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

// permutation of strings is simpler than permutation of array
// vo thoda logical hai zyada
// yahan differnve bus yeh ki hashmap use karo



// using extra space for freq map
class Solution {
private: 
    void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]) {

        // base case
        if(ds.size() == nums.size()) {
            ans.push_back(ds); 
            return; 
        }

        // recursive call, basically iterate over each element and see what all elements are availble for being a part of permutation
        for(int i = 0;i<nums.size();i++) {
            if(!freq[i]) {

                // pushing them in ds and marking them to be true
                ds.push_back(nums[i]);
                freq[i] = 1; 

                recurPermute(ds, nums, ans, freq);

                // unsetting them after recursive call
                freq[i] = 0; 
                ds.pop_back(); 
            }
        }
        
    }
public:

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans; // we will store final answer here 

        vector<int> ds; // one permutation will be stored here

        // creating a frequency array(acts as hashmap, indicating which element is already a part of permutation)
        int *freq = new int[nums.size()]; 

        // intializing freq as 0 for each terms in freq array
        for(int i = 0;i<nums.size();i++){
            freq[i] = 0;
        }  
        // calling the recursive function
        recurPermute(ds, nums, ans, freq);

        return ans; 
    }
};

// without extra space
// using swapping
// start index from 0 and make it go till n
// for every i, swap index with each i
// dry run and you will understand
// this is a fabulous piece of code

class Solution {
private: 
    void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans) {
        if(index == nums.size()) {
            ans.push_back(nums); 
            return; 
        }
        for(int i = index;i<nums.size();i++) {
            swap(nums[index], nums[i]); 
            recurPermute(index+1, nums, ans); 
            swap(nums[index], nums[i]); 
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        recurPermute(0, nums, ans); 
        return ans; 
    }
};