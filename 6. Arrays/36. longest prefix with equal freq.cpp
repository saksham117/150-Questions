#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

// https://leetcode.com/problems/maximum-equal-frequency/discuss/1124403/1224.-Maximum-Equal-Frequency-Solution-Using-Effective-Implementation-or-C%2B%2B-or-Clean


// Intuition:
// After traversing some prefix upto length i(0-indexed), two scenarios are possible:

// All the elements in this prefix have the same number of occurence.

// Then the just next element after this prefix can be removed to get a valid prefix upto index (i + 1)
// and because of this, we can say that the prefix upto index (i + 1) is a valid one and the maximum length so far can be (i + 2)

// All the elements in this prefix have the same number of occurence, except for one element which is an extra

// Example prefix = {2 , 2 , 2 , 3 , 3}
// In this case, we can say that the current prefix upto index i is a valid one and the maximum prefix length can be i + 1

// Implementation:
// The above idea can be implemented in numerous ways, involving mostly hash tables / hash maps. One idea can be:
// At the end of each prefix, we can keep track of the frequencies of all elements traversed so far and how many elements have that frequency.

Implemented Code
int maxEqualFreq(vector<int>& nums) {
	unordered_map <int , int> freq;
	unordered_map <int , int> elements_with_freq;

	int ans = 0 , x , n = nums.size();

	for(int i = 0 ; i < n ; i++) {
		x = nums[i];
		freq[x]++;
		elements_with_freq[freq[x]]++;

		//check if all elements have same frequency
		if(freq[x] * elements_with_freq[freq[x]] == (i + 1)) {
			if(i + 1 < n)
				ans = i + 2;
		}
		//check if all elements have same frequency except for one extra element
		if(freq[x] * elements_with_freq[freq[x]] == i) {
			ans = i + 1;
		}
	}

	return ans;
}