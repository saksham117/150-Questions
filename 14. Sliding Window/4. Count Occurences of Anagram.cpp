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

// also a better way to check of is anagram function
// see adityas video agian to see that approach

class Solution{
public:
    // basically a helper function to check if pattern and text window are anagrams or not
    // checking if their freqMaps match or not
    bool isAnagram(unordered_map<char,int>& freqMap, unordered_map<char,int>& freqPat){
        
        for(auto it: freqPat){
            if(freqMap[it.first] != it.second){
                return false;
            }
        }
        
        return true;
    }
    
    
	int search(string pat, string txt) {
	    // code here

        // creating a freqMap for the pattern
	    unordered_map<char,int> freqPat;
	    for(int i = 0; i < pat.length(); i++){
	        if(freqPat.find(pat[i]) == freqPat.end()){
	            freqPat[pat[i]] = 1;
	        }
	        else{
	            freqPat[pat[i]] += 1;
	        }
	    }
	    
	    
        // freqMap for the text windows
	    unordered_map<char,int> freqMap;
	    
	    int i = 0;
	    int j = 0;
	    int count = 0;
	    
        // iterating over the windos
	    while(j < txt.length()){
	        
            // adding element to the windows
	        if(freqMap.find(txt[j]) == freqMap.end()){
	            freqMap[txt[j]] = 1;
	        }
	        else{
	            freqMap[txt[j]] += 1;
	        }
	        
            // if window size == k
	        if(j-i+1 == pat.length()){
	            
	            if(isAnagram(freqMap,freqPat)){
	                count+=1;
	            }
	            
	            freqMap[txt[i]] -= 1;
	            i++;
	            j++;
	        }
            // if less than K
	        else{
	            j++;
	        }
	    }
	    
	    return count;
	}

};