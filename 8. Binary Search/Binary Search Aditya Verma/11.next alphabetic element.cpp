 // smallest alphabet, greater than the key

 // so we can convert the alphabets into numbers, using
 // typecasting to int
 // and then it just breaks down into the ceil problem
 // done just previously

 // also array is sorted array of letters

  // also another change in condition is
  // ki if key is found, then dont treturn it
  // instead do start = mid + 1


// leetcode question: https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// additonal point in that q: Note that the letters wrap around.
// For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.
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
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int low = 0;
        int high = letters.size() - 1;
        char ans = '0';
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(letters[mid] <= target){
                low = mid + 1;
            }
            else{
                ans = letters[mid];
                high = mid - 1;
            }
        }
        
        if(ans == '0'){
            return letters[0];
        }else{
            return ans;
        }
        
    }
};