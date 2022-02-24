// You Problem Statement: Given two sorted arrays arr1 and arr2 of size m and n respectively, 
// return the median of the two sorted arrays.

// Input format: arr1 = [1,4,7,10,12], arr2 = [2,3,6,15]

// Output format : 6.00000

// Explanation:
// Merge both arrays. Final sorted array is [1,2,3,4,6,7,10,12,15]. We know that to find the median we find the mid element. 
// Since, the size of the element is odd. By formula, the median will be at [(n+1)/2]th position of the final sorted array. 
// Thus, for this example, the median is at [(9+1)/2]th position which is [5]th = 6.

// NAIVE SOLUTION
// Apply nerge function of mergesort to get one sorted merged array
// return its median
// time = O(M+N)
// space = O(m+n)

// space can be refuced to O(1), buy just maintaining a count variable
// and returning the result when count == median element

// better approach
// median in a stream of integers

// best approach
// https://takeuforward.org/data-structure/median-of-two-sorted-arrays-of-different-sizes/
// good question


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>
#include<map>

using namespace std;

float median(int nums1[],int nums2[],int m,int n) {
    if(m>n)
        return median(nums2,nums1,n,m);//ensuring that binary search happens on minimum size array
        
        // doing m+n+1 by 2 takes care of partitons for both odd and even
        // take examples for better understanding
        // if you are taking nothing from any of the arrays
        // assign your ls as INT_MIN and R's as INT_MAX

        // jab mil jaayega ANS
        // to odd and ecen ki median calculation bus differnt thodi si

    int low=0,high=m,medianPos=((m+n)+1)/2;
    while(low<=high) {
        int cut1 = (low+high)>>1;
        int cut2 = medianPos - cut1;
        
        int l1 = (cut1 == 0)? INT_MIN:nums1[cut1-1];
        int l2 = (cut2 == 0)? INT_MIN:nums2[cut2-1];
        int r1 = (cut1 == m)? INT_MAX:nums1[cut1];
        int r2 = (cut2 == n)? INT_MAX:nums2[cut2];
        
        if(l1<=r2 && l2<=r1) {
            if((m+n)%2 != 0)
                return max(l1,l2);
            else 
                return (max(l1,l2)+min(r1,r2))/2.0;
        }
        else if(l1>r2) high = cut1-1;
        else low = cut1+1;
    }
    return 0.0;
}

int main() {
    int nums1[] = {1,4,7,10,12};
    int nums2[] = {2,3,6,15};
    int m = sizeof(nums1)/sizeof(nums1[0]);
    int n = sizeof(nums2)/sizeof(nums2[0]);
    cout<<"The Median of two sorted arrays is"<<fixed<<setprecision(5)
    <<median(nums1,nums2,m,n);
    return 0;
}
