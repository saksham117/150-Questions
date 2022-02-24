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

// start from end index
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // for(int i = 0; i < n; i++)
        // {
        //     nums1.push_back(0);
        // }
        
        
        int count = (m + n) - 1;
        int i = m - 1;
        int j = n - 1;
        
        while(i >= 0 && j >= 0)
        {
            if(nums1[i] > nums2[j])
            {
                nums1[count--] = nums1[i--];
            }
            else
            {
                nums1[count--] = nums2[j--];
            }
        }
        
        
        while(j >= 0)
        {
            nums1[count--] = nums2[j--];        }
        }
};