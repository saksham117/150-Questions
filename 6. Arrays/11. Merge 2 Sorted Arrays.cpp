// IMPORTANT QUESTION
// The leetocode variation is simple: https://leetcode.com/problems/merge-sorted-array/

// The gfg problem is tough

// 1st approach: Create an additonal memory and then apply simple merge algo
// Then copy that array into arr1 and arr2 

// 2nd approach: Cant use extra space 
// So for that maintain two pointers i and j
// if arr[i] <= arr[j], nothing needs to be done, that element is at correct poistion
// else swap(arr[i], arr[j])
// now since we need to keep array 2 sorted, we will place this element at the correct position(like insertion sort)
// as soon as i reaches end, stop
// T= O(n1Xm1)


// This is tough!! Not that easy at all. Ask only if interviewer wants it 

// 3rd Approch : Use Gap method
// even striver does not have the intuition for it
// so just go ahead and tell about the algo

// Intially take gap as n1+m1/2 
// so i will point at 0 and j will point at index equivalnt to gap(this is the index, if both the array were a single array)

// if(arr[i] <= arr[gap])
// move both pointers ahead
// else
// swap them and move both pointers ahead
// once j goes out of index
// make gap as gap/2 

// so again i = 0 and j = gap 
// apply the same algo 
// we stop when loop for gap == 1 stops


// if n1+m1 is odd
// then take gap as ceil of (n1+m1)/2 
// not floor!!!!
// iski complexity logn*n
// logn from gap and n if we swap all elements

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

// Function to find next gap.
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}
 
void merge(int* arr1, int* arr2, int n, int m)
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        // comparing elements in the first array.
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
 
        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0;
             i < n && j < m;
             i++, j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
 
        if (j < m) {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
        }
    }
}