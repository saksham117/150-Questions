// bitonic array is one which first monotonically increase (that is a[i] < a[i+1])
// and then it monotonically decreases
// for example [1,3,8,12,4,2]
// it increases monotonicaaly till 12
// after that it monotonically decreases

// We need to find the maximum in that bitonic array

// So from prev video we can say, maximum elemen is just the peak of this bitonic array
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

class Solution{
public:
	int findPeakElement(int nums[], int n) {

        int low = 0;
        int high = n - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            bool left = true;
            bool right = true;

            if(mid-1 >= 0 && nums[mid] <= nums[mid-1]){
                left = false;
            }

            if(mid+1 < n && nums[mid] <= nums[mid+1]){
                right = false;
            }

            if(left && right){
                return mid;
            }
            else{
                if(mid - 1 < 0){
                    low = mid + 1;
                }
                else if(mid + 1 >= n)
                {
                    high = mid - 1;
                }
                else if(nums[mid - 1] > nums[mid]){
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }

            }
        }

        return -1;
    }

	int findMaximum(int arr[], int n) {
	    // code here
        return arr[findPeakElement(arr, n)];
	}
};
