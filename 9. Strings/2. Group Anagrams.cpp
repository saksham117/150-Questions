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

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
// typically using all the original letters exactly once.

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// We will be using a hashmap
// so it will be of type
// unordered_map< unordered_map<char,freq> , vector<string>>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // key will be a freq map
        // so for words like cat tac act, freqmap will be same
        // and in bigMap, they will have this freqMap as key and inside value all these strings as a vector
        unordered_map<unordered_map<char,int> , vector<string>> bigMap;

        for(int i = 0; i < strs.size(); i++){

            string str = strs[i]; // retreiving the string one by one

            unordered_map<char,int> freqMap; // creating a freqmap for this string
            for(int j = 0; j < str.length(); j++){
                if(freqMap.find(str[j]) != freqMap.end()){
                    freqMap[str[i]] += 1;
                }
                else{
                    freqMap[str[i]] = 0;
                }
            }

            // locating if this freqmap is already present in the bigMap or not
            if(bigMap.find(freqMap) != bigMap.end()){
                bigMap[freqMap].push_back(str);
            }
            else{
                vector<string> temp;
                temp.push_back(str);
                bigMap[freqMap] = temp;
            }
        }

        vector<vector<string>> ans;

        for(auto it: bigMap){
            ans.push_back(it.second);
        }

        return ans;
    }
};


// This above code does not work in c++
// so we map of this type
// unordered_map<string, vector<string>>
// so how will we maintain freqmap over here?

// we will sort the string, and then make it as the key 
class Solution {
public:
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        for(auto i:strs){
            string word=i;
            sort(i.begin(),i.end());
            mp[i].push_back(word);
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};


// Moreover, since the string only contains lower-case alphabets, we can sort them 
// using counting sort to improve the time complexity.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
private:
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};