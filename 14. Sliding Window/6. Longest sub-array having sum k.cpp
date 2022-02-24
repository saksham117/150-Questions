#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<set>
#include<map>

using namespace std;
// Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with 
// the sum of the elements equal to the given value K

// this approach is fairly simple but only works for case when numbers are all positive or 0
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int i = 0;
        int j = 0;
        int sum = 0;
        int maxLen = 0;
        
        while(j < N){
            
            sum += A[j]; // do this everytime (fixed size main be we used to do this)
            
            if(sum < K){
                j++; // if sum is less than K, we need to add more elements to our subarray
            }
            else if(sum == K){
                // if sum is exactly K, check if it is of greatest length
                if(j-i+1 > maxLen){
                    maxLen = j-i+1;
                }
                
                j++; // carry on our quest
            }
            else if(sum > K){
                // now we need to continually remove elements as sum is greater
                while(sum > K){
                    sum = sum - A[i];
                    i++;
                }
                
                j++;
            }
        }
        
        return maxLen;
        
    } 

};

// for negative number, use this approach invovling negative numbers
// https://www.geeksforgeeks.org/longest-sub-array-sum-k/


// C++ implementation to find the length
// of longest subarray having sum k


// approach very similar to largest subarray with 0 sum

// function to find the length of longest
// subarray having sum k
int lenOfLongSubarr(int arr[],
					int n,
					int k)
{

	// unordered_map 'um' implemented
	// as hash table
	unordered_map<int, int> um;
	int sum = 0, maxLen = 0;

	// traverse the given array
	for (int i = 0; i < n; i++) {

		// accumulate sum
		sum += arr[i];

		// when subarray starts from index '0'
		if (sum == k)
			maxLen = i + 1;

		// make an entry for 'sum' if it is
		// not present in 'um'
		if (um.find(sum) == um.end())
			um[sum] = i;

		// check if 'sum-k' is present in 'um'
		// or not
		if (um.find(sum - k) != um.end()) {

			// update maxLength
			if (maxLen < (i - um[sum - k]))
				maxLen = i - um[sum - k];
		}
	}

	// required maximum length
	return maxLen;
}

// Driver Code
int main()
{
	int arr[] = {10, 5, 2, 7, 1, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 15;
	cout << "Length = "
		<< lenOfLongSubarr(arr, n, k);
	return 0;
}
