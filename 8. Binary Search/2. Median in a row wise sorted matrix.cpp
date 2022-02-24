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

// All the rows of the matrix will be sorted
// And also, no of rows and cols are gonna be odd
// Also, the values of the matrix can range from 1 to 10^9

// Naive approach
// Iterate over the matrix and one by one put all the elements in a ds like vector
// After that. sort that vector and return the middle most element


// Efficent Algorithm
// We know that median, will be somewhere in between 1 and 10^9, coz thats the range of the individual elements of the matrix
// Take search space as 1-10^9 and set low as 1 and high as 10^9
// Now calculate the mid

// To make things simple, we will for now assume search space to be 1 to 15
// middle = 8

// So what we will do is that, for every row in matrix, we will see how many elements are less than or equal to the middle element
// like for every row, check no of elements <= middle(8, in our case)

// This can be easily done in log(m) time using Binary search. Basically using the funda of finding last occurence of the
// middle element in the array 
// So if we do this for each row of size m, and there are N such rows, it will take us
// Nlog(m) time

// So lets say if we sum that up acorss rows, there are 7 elements <= 8
// so we reduce our search space and move it to 1-7
// We go left becasue if we go right, the number of values less than mid are only gonna increase as we are checking
// using a larger number


// This is a better explanation of the algo
// https://afteracademy.com/blog/median-in-a-row-wise-sorted-matrix
// https://tutorialspoint.dev/data-structure/matrix-archives/find-median-row-wise-sorted-matrix

// Optimized Solution Using Binary Search
// Solution idea

// The idea here is to leverage the binary search algorithm in order to optimize this problem. 
// If you have paid attention to the definition of median, you must have noticed in case of odd elements 
// the median is (1+N*M)/2 th smallest number which basically implies that (1+N*M)/2 is the total number 
// of elements which are smaller or equal to our median.One more thing to analyse is, the median will 
// always lie in the range of minimum and maximum element.Using these observations and applying binary 
// search for elements in the above range (minimum, maximum) and maintaing the counter for smaller or 
// equal numbers for each element in this range, we can find our median(discussed above based on count of smaller or equal elements).

// Solution idea

// Let us see a step-by-step approach to this solution:

// First, we need to find the minimum and maximum elements from the matrix. The minimum and maximum can be easily 
// found since the rows are sorted so we need to comapare with the first element of each row for minimum and last element 
// of each row for maximum.
// After finding our min and max, we can apply binary search on this range. The mid element can be calculated and number of 
// elements smaller or equal to mid can be calculated, we have used upper_bound() function for this.
// Based on the value of our counter, the min and max can be adjusted accordingly based on what we do for binary search.



int medianRowwiseSortedMatrix(int matrix[N][M])
{
    int min = INT_MAX;
    int max = INT_MIN;
    int desired_count = (1+(N*M)/2));
   for(int i=0;i<N;i++)
    {
        if(A[i][0]<min)
        min = A[i][0];
        if(A[i][M-1]>max)
        max = A[i][M-1];
    }
    int counter =0;
    while(min<max)
    {
        int counter=0;
        int mid = (max+min)/2;
        for(int i= 0;i<N;i++)
        {
            counter += upper_bound(A[i], A[i]+M, mid) -  A[i];
        }
        if(counter < desired_count)
            min = mid+1;
        else
            max = mid;
    }
    return min;
}



// Instead of upper bound, we can calculate the last occure of an element in a binary array(will have to be modified a bit)
// to calculate number of elements <= mid