// https://leetcode.com/problems/minimum-window-substring/

// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every 
// character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// A substring is a contiguous sequence of characters within the string.

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

// NOTE
// If pattern is "toc" and somwhere in my string, I find "ottc"
// then in that case "ottc" will be a valid substring. The question basically wants that the 
// the number of characters in the pattern should be present in the substring. If more are present no issue
// but atleast the characters in the pattern with that same frequency should be present in the substring
// here atleast is very important

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<set>
#include<map>

using namespace std;


//  I coded this myself

class Solution {
public:
    string minWindow(string s, string t) {
        
//         decalring the variables for 2 pointer approach
        int i = 0, j = 0;
        int minLen = INT_MAX;
        string ans = "";
        int n = s.length();
        int m = t.length();
        
//         creating two unordered_maps, one for pattern and one for keeping a trace of current 
//         window contents
        unordered_map<char,int> patternMap;
        unordered_map<char,int> freqMap;

//         creating the map for the pattern
        for(int x = 0; x < m; x++){
            patternMap[t[x]]++;
        }
    
//         now decalring varaibles that will control our window condition
        int count = 0;
        int k = patternMap.size();
        
//         starting the traversal
        while(j < n){
            
//             case 1, when all elemenst have not been found
            if(count < k){
                if(patternMap.find(s[j]) != patternMap.end()){
                    freqMap[s[j]]++;
                    
//                     if freqeuncy is eaxctly same, then increment count by 1
                    if(freqMap[s[j]] == patternMap[s[j]]){
                        count++;
                    }
                }
            }
            
//             if the frequency exaclty matches in the given windo, try to find if a smaller 
//             window exists that follows the same pattern as our given pattern
            if(count == k){
                
                while(count == k){
//                     calculation of the answer
                    // cout<<i<<" "<<j<<'\n';
                    if(j-i+1 < minLen){
                        minLen = j-i+1;
                        ans = s.substr(i, minLen); // second argument is length
                    }
                    
//                     trying to reduce the window
                    if(freqMap.find(s[i]) != freqMap.end()){
                        freqMap[s[i]]--;
                        //seeeing if I have atleast the given frequency as required in the pattern
                        if(freqMap[s[i]] < patternMap[s[i]]){
                            count--; 
                        }
                    }
                    i++;
                }
            }
            
            j++;
        }
        
    return ans;
        
    }
};