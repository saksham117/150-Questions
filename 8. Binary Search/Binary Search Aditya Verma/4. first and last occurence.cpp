#include<vector>
using namespace std;


// do not follow this bottom approach
// just first find first occurence by modifying binary serach when key found once
// and then find last occurence and then return both the answers
// do iteratively for easy code. Just write down and you shall see how simple it is




class Solution {
public:

    int BinarySearch(vector<int>& arr, int n, int key, int low, int high)
    {
        if(low > high)
        {
            return -1;
        }

        // calculating mid like this, coz in good level tests doing low + mid will cause buffer overflow
        int mid = low + (high - low)/2;

        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] > key)
        {
            return BinarySearch(arr,n,key,low,mid-1);
        }
        else
        {
            return BinarySearch(arr,n,key,mid+1,high);
        }
    }



    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();
        int low = 0;
        int high = n -1;

        int index = BinarySearch(nums,n,target,low,high);
        vector<int> output;
        if(index == -1)
        {
            output.push_back(-1);
            output.push_back(-1);
            return output;
        }

        int first = index;
        int last = index;

        int temp_first = index;
        int temp_last = index;

        while(temp_first != -1)
        {
            temp_first = BinarySearch(nums,n,target,low,temp_first-1);
            if(temp_first != -1)
            {
                first = temp_first;
            }
        }

        while(temp_last != -1)
        {
            temp_last = BinarySearch(nums,n,target,temp_last + 1,high);

            if(temp_last != -1)
            {
                last = temp_last;
            }
        }

        output.push_back(first);
        output.push_back(last);

        return output;
        
    }
};