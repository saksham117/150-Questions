// /EASY

// You will be given k sorted arrays/linked list 
// merge thes k sorted arrays into a single sorted array

// Brute force
// Pick two arrays and merge them. I know how to do this
// this will take time O(kXN)

// Opimal
// So we know how to merge 2 arrays
// We need to generalize it to k arrays
// so what we need is that we need some mechanism to point to the smallest element in each of these k arrays

// so what we can do is make use of minHeap
// minheap of type pair<value, pair<arrayNo, index>> 
// so intially we will push k elements into minHeap, one from each array
// and have a size variable == k
// so we will pop the minimum element from heap(O(1)) operation
// and since we have popped from that array, we will also insert the next elemet from that array
// rinse and repeat

// when ome array gets exhausted, reduxe size by 1 (zaroorat nahi hai vaise size maintain karne ki)
// uske bina bhi chal jaayega

// repeat this algo till size == 1
// after that whatever array is still left, push its elements dirctly into the final output array

// if we were given a linkedlist, then we just need to maintain the value and the node
// coz node is address and also has access to next node

// Time complexity complexity to N*log(K).
// i have done it both on leetcode and gfg  