// Going to be the best question so far

// Given an array of integers A of size N and an integer B.
// College library has N books,the ith book has A[i] number of pages.
// You have to allocate books to B number of students so that maximum number of pages alloted to a student is minimum.

// Some rules
// A book will be allocated to exactly one student.
// Each student has to be allocated at least one book.
// Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.
// Calculate and return that minimum possible number.

// NOTE: Return -1 if a valid assignment is not possible.

// example: arr = [12,34,67,90]
// n = 4, students(B) = 2

// In interview also, do not talk about recursive or dp solution. Is gonna waste a lot of time
// Coz optimed solution itself takes a lot of time

//  ############### Algorithm ###############
// So again, we will be implementing binary search on the search space
// so we need to decide upon low and high. 
// low can be assigned as the minimum element of the array (in arr like [12,1,30,40])
// 1 is the minimum, but it can never be a valid allocation as it will result in non contiguos arrays
// However, we know answer cannot go less than this, so thats why we just set a lower bound
// Also, so high can be set as the summation of all the elements in the array
// both operations will take O(N) time

// Now figure out the mid
// So we wil;l now try to assign books, such that maximum allotment of books cannot be greater than middle(107 in our case)
// if it is not possible to do so, go to right and check for a higher bound
// else if its possible store it as a possible answer and move further to left



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

class Solution 
{
    public:
    bool isPossible(int arr[], int N, int M, int limit){
        int allocated_students = 1;
        int pages = 0;

        for(int i = 0; i < N; i++){
            if(arr[i] > limit){
                return false; // if one element becomes greater than barries itself, then we cannot do anything
                // have to return false
            }

            if(arr[i] + pages > limit){
                allocated_students += 1; // if the pages exceed barrier
                pages = 0; // assign it to next student, but also set pages allocated to this new student as zero first
                pages += arr[i];
            }
            else{
                pages += arr[i]; // increment the pages allocated to him
            }
        }

        // if such an allocation is not possible
        if(allocated_students > M){
            return false;
        }

        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int arr[], int N, int M) 
    {
        //code here
        
        // calculating low and high
        int low = INT_MAX;
        int high = 0;

        if(N < M){  // if number of books are less than no of students
            return -1;
        }

        for(int i = 0; i < N; i++){
            if(arr[i] < low){
                low = arr[i];
            }

            high += arr[i];
        }

        // looking over the search soace
        while(low <= high){

            int mid = low + (high-low)/2;

            if(isPossible(arr,N,M,mid)){
                high = mid -1; // go left
            }
            else{
                low = mid+1; // go right
            }
        }

        return low; //low will always have the answer
    }
};