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

// Given an integer array nums, return the number of reverse pairs in the array.
// A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

// First approach
// Naive approach: O(N^2)
// compare every element with everyother element

// Optimal Approach
// Problem solution will be similar to inversion count
// We are doing normal merge sort
// just in the merge function, before merging the 2 arrays
// we are counting the pairs


class Solution {
public:
    int Merge(vector < int > & nums, int low, int mid, int high) {
  int total = 0;
  int j = mid + 1;
//   counting the pairs, before merging the arrays
  for (int i = low; i <= mid; i++) {
    while (j <= high && nums[i] > (long long )2 * nums[j]) {
      j++;
    }
    total += (j - (mid + 1));
  }

  vector < int > t;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high) {

    if (nums[left] <= nums[right]) {
      t.push_back(nums[left++]);
    } else {
      t.push_back(nums[right++]);
    }
  }

  while (left <= mid) {
    t.push_back(nums[left++]);
  }
  while (right <= high) {
    t.push_back(nums[right++]);
  }

  for (int i = low; i <= high; i++) {
    nums[i] = t[i - low];
  }
  return total;
}
int MergeSort(vector < int > & nums, int low, int high) {

      if (low >= high) return 0;
      int mid = (low + high) / 2;
      int inv = MergeSort(nums, low, mid);
      inv += MergeSort(nums, mid + 1, high);
      inv += Merge(nums, low, mid, high);
      return inv;
}
    int reversePairs(vector<int>& arr) {
        return MergeSort(arr, 0, arr.size() - 1);
    }
};