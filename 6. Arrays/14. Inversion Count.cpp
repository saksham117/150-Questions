// Count the number of pairs of i and j, suhc that a[i] > a[j] for i < j
// for arr [8,4,2,1] inversions are 6 in number

// Brute Force
// 1) using 2 for loops, pick up arr[i] and check for all j > i
// O(N^2) approach

// Optimal Method (Using Merge Sort Technique)
// Normal Merge sort. Only change when a[i] > a[j]. That is where we wil count!!

// https://takeuforward.org/data-structure/count-inversions-in-an-array/

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
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    // example array [5,3,2,1,4] 
    
    long long int count = 0;

    void merge(long long arr[], long long low, long long mid, long long high, long long N)
    {
        long long copy[N];
        long long i = low;
        long long j = mid + 1;
        long long k = low;

        while(i <= mid && j <= high)
        {
            if(arr[i] <= arr[j])
            {
                copy[k++] = arr[i++];
            }
            else{
                count += (mid - i) + 1;
                copy[k++] = arr[j++];
            }
        }

        for(; i <= mid; i++)
        {
            copy[k++] = arr[i];
        }

        for(; j <= high; j++)
        {
            copy[k++] = arr[j];
        }
        
        
        i = low;
        for(; i <= high; i++)
        {
            arr[i] = copy[i];
        }
        
    }

    void mergeSort(long long arr[], long long low, long long high, long long N)
    {
        if(low >= high)
        {
            return;
        }
 
        long long mid = low + (high - low)/2;

        mergeSort(arr, low, mid, N);
        mergeSort(arr, mid + 1, high, N);
        merge(arr, low, mid, high, N);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long low = 0;
        long long high = N-1;
        mergeSort(arr, low, high, N);
        return count;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}