// Given a string s, find the length of the longest substring without repeating characters.
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Naive Approach
// This approach consists of taking the two loops one for traversing the string and another loop – nested loop 
// for finding different substrings and after that, we will check for all substrings one by one and check for each 
// and every element if the element is not found then we will store that element in HashSet otherwise we will break
// from the loop and count it.


// Better Approach
// take a left pointer and a right pointer
// and also declare a set which will store the unique elements
// we also declare a len variable which shall store length of longest substring without repeat
// range l-r will be such that there will be no repeating characters
// so len = r-l+1

// if we find a character, such that it already exists in the set, we see str[l], pop it from set
// and move left forward. We continue to do this, till str[l] is not present in the set

// Pointer ‘left’ is used for maintaining the starting point of substring while ‘right’ will maintain the endpoint of the 
// substring.’ right’ pointer will move forward and check for the duplicate occurrence of the current element if found 
// then ‘left’ pointer will be shifted ahead so as to delete the duplicate elements.

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

// this first approach is just variable size sliding window approach as taught by Aditya Verma
// the code I wrote there and the code I wrote here are almost the same, only difference being here I used set
// but both are being used for same objective

// the second approach at bottom is more optimal and not that intuitive
// but need to remeber just in case asked in interview
// as I coded it myslef, should not be that tough

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // the two pointers
        int left = 0;
        int right = 0;
        int l = 0; // length of LLS
        int n = s.size(); 

        // for storing unique characters
        unordered_set<char> characters;

        while(right < n){
            // if the charcater is not yet in set
            if(characters.find(s[right]) == characters.end()){
                characters.insert(s[right]);
                l = max(l, right - left + 1);
                right+=1;
            }
            else{
                // keep on moving left and removing from set till the duplicate gets removed
                while(characters.find(s[right]) != characters.end()){
                    characters.erase(s[left]);
                    left += 1;
                }
            }
        }

        return l;
    }
};

// Time complexit: is O(N) or more accurately O(2N)
// Time Complexity: O( 2*N ) (sometimes left and right both have to travel complete array)
// lin in the case arr: a b c d e f z z (last two eleemnts are same)
// Space Complexity: O(N) where N is the size of HashSet taken for storing the elements

// Next optimal approach
// Instead of storing in a set
// store in unorder_map, where we will store element along with the last index where it occured
// so in this way, it would help us to move the left pointer directly where we want it, insetad of moving it 1 by one  
// need to uderstand how it updates         //  

//  I coded this on my own. Does invovlve some though and trial and error on examples
// but not that tough
// maintain your calm
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashMap; // for storing char and index of it last occurence
        
        int len = 0;
        int maxLen = 0;
        int startIndex = 0; // starting index of that string such that no repeating characters exist
        
        for(int i = 0; i < s.length(); i++){
            if(hashMap.find(s[i]) == hashMap.end()){ // if it is a new character
                len += 1;
                hashMap[s[i]] = i;
            }
            else{ // if already present in our hashmap
                if(hashMap[s[i]] + 1 > startIndex){  // check if my startIIndex is already ahead of it or not
                    startIndex = hashMap[s[i]] + 1;  // hashMap[s[i]] + 1 indicates the just next position to where the last
                }                                    // repeating character occured in our string 
                len = i - startIndex + 1; // update the length
                hashMap[s[i]] = i; // update the index
            }
            
            if(len > maxLen){
                maxLen = len;
            }
        }
        
        return maxLen;
        
    }
};