// Also known as largest minimum distance 
// You will be given an array
// Here arr = [1,2,4,8,9], where a[i] denotes the location of a stall
// it might not be given in the sorted order
// we will also be given certian number of cows, say here we are given 3
// The number of cows can range from 2 to n, where n is no of stalls 

// You need to place these k cows in these n stalls, such that the minimum distance between any two cows is maximum possible 
// or largest minimum distnace

// Brute force: Try out all possible configurations via recursion

// Optimized: Binary search
// set lower bound to 1
// upper bound = maxElementOfArray - 1 (here = 9-1 = 8)


// Same problem on leetcode: 1552. Magnetic Force Between Two Balls
// link: https://takeuforward.org/data-structure/aggressive-cows-detailed-solution/

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

class Solution {
public:

    bool isPossible(vector<int>& position, int m, int middle){
        int allocated = 1; // allocate cow 0 to index 0 and incremen count by 1
        int lastIndex = 0;
        int i = 1;

        // while lesser cows have been allocatd or we are within range
        while(allocated < m && i < position.size()){
            // if difference is greater than what we set
            // set that as last alloted index and increment cow by 1
            if(position[i] - position[lastIndex] >= middle){
                allocated += 1;
                lastIndex = i;
            }
        }

        // if at the end, we were able to allocate the cows, then return true
        if(allocated >= m){
            return true;
        }
        else{
            return false;
        }
        
    }

    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end()); // very imortant to sort in this q as we have to work with co ordinates and
        // select them greadily
        int low = 1; //low will always be 1
        int high = position[position.size() - 1] - position[0]; // element at last index - element at first index
        int res = 0;
        

        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            // if cows can be placed at this distance, search for a greater distance
            if(isPossible(position,m,mid)){
                res = low;
                low = mid+1;
            }
            // else search for a smaller distance
            else{
                high = mid-1;
            }
        }

        return high;    // or return res
    }
};
