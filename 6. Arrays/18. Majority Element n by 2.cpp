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

// Approach 1
// Take a hashmap and maintain count. Space O(N) and time O(N)

// Approach 2
// Sorting and find element at index n/2

// Approach 3: Moores Voting Algorithm
// Take 2 variables, count and element and initialize both to 0
// and we linearly iterate from first element to the last element

// eg arr = 7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5

// algo

// if(count == 0){
//     el = a[i];
// }

// if(el == a[i]){
//     count += 1;
// }
// else{
//     count -= 1;
// }

// Intuiton behind this
// Since it has been mentioned that one element will occur more than floor(n/2) times

// If there is a majority element, the algorithm will always find it. 
// For, supposing that the majority element is m, let c be a number defined at any step of the algorithm to be either the counter, 
// if the stored element is m, or the negation of the counter otherwise. 
// Then at each step in which the algorithm encounters a value equal to m, the value of c will increase by one, 
// and at each step at which it encounters a different value, the value of c may either increase or decrease by one. 
// If m truly is the majority, there will be more increases than decreases, and c will be positive at the end of the 
// algorithm. But this can be true only when the final stored element is m, the majority element

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int count = 0;
        int element = 0;

        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                element = nums[i];
            }

            if(element == nums[i]){
                count += 1;
            }
            else{
                count -= 1;
            }
        }

        return element;
        
    }
};

// More details

// The explanation :

// Assume there is a majority element. If there isnt, then this eill return a semi arbitrary value, 
// which is why the result must be validated, so we just need to show it will find the majority element if it exists.

// As you go through a section of thr array and keep a count, a positive count means that at least 
// half of the values you have seen in that section are the value you are tracking.

// So let's say we reach a point n in thr array, and our count hits 0. We either have the most common 
// element right now, or we don't.

// If we don't, then the preceding section of the array is half filled eith the wrong value, and has, 
// at most, half of it filled with the right value. So even if it was half filled with the majority element, 
// the remainder of the array must have the majority element as its majority.

// Similarly, if thr element we had was the majority element, the last section of thr array was half 
// filled with it, so the remainder of the array must be a majority of the value still.

// In short, if oir count hits 0, we know the rest of the array is an array with thr same majority value as the full array.

// If the next number we pick to try isn't the majority, our count will hit 0 again, and we have a smaller array to check.

// If it is the majority, it will either hit 0, and we have to try again on the remainder of the array, 
// or we reach the end with a positive count, and have our candidate.

// In short, we can test a section of the array, and either find the candidate, or reduce the problem 
// to a smaller size. And this works out to a constant n cost, as you always Iterate through every element once.

// https://www.quora.com/What-is-an-intuitive-explanation-of-Moores-voting-algorithm