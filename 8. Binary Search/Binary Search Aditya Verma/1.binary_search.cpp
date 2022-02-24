#include<iostream>
using namespace std;

int BinarySearch(int *arr, int n, int key, int low, int high)
{
    if(low > high)
    {
        return -1;
    }

    // calculating mid like this, coz in good level tests doing low + mid will cause buffer overflow
    int mid = low + (high - low)/2;

    if(arr[mid] == key)
    {
        return mid;
    }
    else if(arr[mid] > key)
    {
        return BinarySearch(arr,n,key,low,mid-1);
    }
    else
    {
        return BinarySearch(arr,n,key,mid+1,high);
    }
}

int main()
{   
    int n; // assign n some value

    int * arr = new int[n]; // fill in the array

    int low = 0;
    int high = n -1;

    int key; // assign some key

    // ans is the index here element is present
    int ans = BinarySearch(arr,n,key,low,high);

    return 0;
}

// iterative method
int BinarySearch(int *arr, int n, int key)
{
    int low = 0;
    int high = n-1;

    while(low <= high){
        
        int mid = low + (high-low)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }

    return -1;
}