// Brute Force approach
// series is increeasing, keep on incrementing count
// as soon as it decrease
// return len(array) - count

// 2 5 6 8 11 12 15 18
// 11 12 15 18 2 5 6 8
// 6 8 11 12 15 18 2 5

// Optimal
// number of times array is rotated = index of minimum element(will be calculated differntly if rotations is made opposite)
// currently its clockwise

// so using binary search we need to find index of minimum element
// for that we need to know two thing

// 1) is it minimum or not
// 2) if it is not, where to go

// so dealing with 1
// if it is minimum element, then element to its just left would be greater than it
// we need to check mid+1 too

// now dealing with 2nd step
// if mid is not minimum
// then compare mid with start index
// if mid > start, this means, that array to left is sorted and we need to search right
// else if mid < start, this means array is not sorted and we need to search in left
// minimum element will always lie in unsorted side

// when going left right
// insted of updating mid as mid -1 or mid + 1
// let mid be mid only and then update low, high, whatever be the case 

// binary_min function implements all of that
// we can skip the second if statement, if we want
 
 // BELOW QUESTION IS TO FIND THE MINIMUM ELEMENT IN A ROTATED SORTED ARRAY 
 #include<vector>
 using namespace std;

class Solution {
public:

    int binary_min(vector<int>& nums, int low, int high, int n)
    {   
        // base case
        if(low > high)
        {
            return -1;
        }

        // caclualting mid
        int mid = low + (high - low)/2;

        // if element is smaller than element to left
        // then it is the answer
        // used modulo to avoid overflow
        if(nums[mid] < nums[(mid + n -1)%n])
        {
            return nums[mid];
        }
        // if element to right is smaller then, right element is the answer
        else if(nums[mid] > nums[(mid + 1)%n])
        {
            return nums[(mid + 1)%n];
        }
        // if low is greater than mid, this means we need to check in left array
        else if(nums[low] > nums[mid])
        {
            return binary_min(nums,low,mid,n);
        }
        // else check in right array
        else{
            return binary_min(nums,mid,high,n);
        }
    }

    int findMin(vector<int>& nums) {

        int n = nums.size();
        int low = 0;
        int high = n - 1;
        
        if(n == 1)
        {
            return nums[0];
        }
        
        if(n == 2)
        {
            return min(nums[0], nums[1]);
        }
        
        if(n == 3)
        {
            return min(nums[0], min(nums[1], nums[2]));
        }
        
        if(nums[low] < nums[high])
        {
            return nums[low];
        }

        return binary_min(nums,low,high,n);

    }
};

// iterative way
class Solution {
public:
    int findMin(vector<int>& arr) {
        
        int n = arr.size();
        int low = 0;
        int high =  n - 1;
        
        // if there is only a single element
        if(n == 1)
        {
            return arr[0];
        }
        
        // if there is no rotation
        if(arr[low] < arr[high])
        {
            return arr[low];
        }

        // loop while condition is true
        while(low <= high){

            int mid = low + (high-low)/2;

            // used modulo to avoid overflow for edge case when we are at 0 or n-1
            // if value at mid is less than prev value, then mid is min index
            if(arr[mid] < arr[(mid + n -1)%n]){
                return arr[mid];
            }
            // else if value of mid+1 is less than value at mid, then mid+1 is index // NEED TO CHECK BOTH
            if(arr[mid] > arr[(mid + 1)%n])
            {
                return arr[(mid + 1)%n];
            }
            else if(arr[mid] > arr[low]){
                low = mid; // check in right
            }
            else{
                high = mid;
            }
        }

    return -1;        
    }
};


// this I code myself while revision
// this is rotation finding  element finding
class Solution {
public:
    
    int binarySearch(vector<int>& arr, int target, int low, int high){
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return -1;
    }
    int search(vector<int>& arr, int target) {
        
//         first we will be locating the pivot point
        int low = 0;
        int high = arr.size() - 1;
        
        
        
        int pivotIndex = 0; // this takes care of case when rotation = 0 or when no of elements are 1
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            if(mid - 1 >= 0 && arr[mid] < arr[mid-1]){
                pivotIndex = mid;
                break;
            }
            else if(mid + 1 < arr.size() && arr[mid+1] < arr[mid]){
                pivotIndex = mid+1;
                break;
            }
            
            else if(arr[mid] > arr[low]){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        
        if(arr.size() == 1){
            if(target == arr[0]){
                return 0;
            }
            return -1;
        }
        
        int start1 = 0;
        int end1 = pivotIndex - 1;
        
        int start2 = pivotIndex;
        int end2 = arr.size() - 1;
        
        if(end1 >= 0 && arr[start1] <= target && target <= arr[end1]){
            return binarySearch(arr,target,start1,end1);
        }
        else if(arr[start2] <= target && target <= arr[end2]){
            return binarySearch(arr,target,start2,end2);
        }
        return -1;
    }
};