// Simple
// we will be given an array, say [1,3,8,12,4,2], we need to find if key = 4 exists or not

// So what we can do is
// 1) Find max of bitonic array(Using Peak method in logn time)
// 2) Now we have 2 sorted arrays, from 0 to max_index in increasing fashion
// max_index+1 to n-1 in decreasing fashion
// 3) So first search if key is present in first sorted array using bs. If found return key.
//    if not found, serach in other array. But keep note this array is sorted in reverse order
// If key not found in both arrays, return -1

