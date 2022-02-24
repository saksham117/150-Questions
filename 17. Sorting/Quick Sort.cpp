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


// Can be asked directly in an interview 
// basic funda is, that at every iteration we try that every element in front of me should be smaller than me
// and every element behind me should be greater than me 

// example: arr = 4 6 2 5 7 9 1 3
// so we pick any element at random and tell that guy to send all numbers smaller than it befire it and all greate after it 
// so lets say we pick the 0th element
// lets define it as pivot
// so take 2 pointers, i and j(i at 0th and j at n-1, intially)
// continue moving i forward, till arr[i] <= pivot
// continue moving j backwards till arr[j] > pivot 
// swap(arr[i] and arr[j]) and continue moving forward
// do this till i <= j
// when j < i, swap arr[pivot] with arr[j]
// so after one iteration we can say that pivot element is now at its sorted position  
// so this above logic is called partitioning logic (just like merge func of merge sort)

// and then make a recursive call from start to j-1 and j+1 to end
// just like mergesorts recursive calls 

// will return the index of the pivot element after being placed in the correct location
// this will help us to go to the other subarrays to sort the complete array 



class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
         if(low >= high){
             return;
         }
    
        int j = partition(arr,low,high);
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
    
    
}
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
     int pivot = arr[low];

    int i = low;
    int j = high; 

    while(i < j){
        
        // increment i till its less than or equal to pivot
        while(i <= high && arr[i] <= pivot){
            i++;
        }

        // keep on decrementing j till its greater then pivot 
        while(j >= low && arr[j] > pivot){
            j--;
        }

        // once we exit, element at i and j wont be satisfying the above conditiond
        if(i < j){
            swap(arr[i],arr[j]); // only swap 
            
        }

    }
            swap(arr[low],arr[j]); // dont swap pivot and arr[j]: wont work
            return j;
    }
};

  
// time complexity
// O(NlogN)
// as tree will be formed
// of height logn
// and at every level we ared doing N operatrions
// see tree to better understand
// this is the best case(when array is laways divided into 2 equal halves)

// worst case O(N^2)
// when array is already sorted
// in that case for 1st call i have to do n omparison
// for next n-1
// and so on
// yeh issliye coz ek side kuch nahi higa
// and sab doosri side karna hoga 

// to improve this, pick the middle element as pivot
// O(N) space complexity due to recursion stack