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


// it is just the table formul;ation phase of kmp algo
// nothing else


class Solution{
  public:		
	int lps(string pattern) {
	    // Your code goes here
	    int m = pattern.length();

    // first creating the prefix suffix table
        int* table = new int[m];
    
        table[0] = 0; // start element will always be zero
        int i = 0;
        int j = 1;
        
        // int max = 0;
    
        while(j < m){
            
            if(pattern[i] == pattern[j]){
                table[j] = i + 1;
            //     if(table[j] > max){
            //     max = table[j];
            // }
                i++;
                j++;
            }
            else{
                if(i == 0){
                    table[j] = 0;
                    j++;
                }
                else if(i != 0){
                    i = table[i-1];
                }
            }
            
            
        }
        

        return table[m-1];
        
	}
};