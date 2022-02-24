// this is the link: https://www.youtube.com/watch?v=BXCEFAzhxGY
// what KMP does is that it takes advantage of the successful comparisons we have already done
// in my nb, in whioch I practiced the code, I have written it down with pen and paper
// when time is there, make it fair
// excellently understood

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

// return the index of first occurence of the pattern
// have done a similar q on gfg: https://practice.geeksforgeeks.org/problems/search-pattern0205/1/?category[]=Pattern%20Searching&category[]=Pattern%20Searching&page=1&query=category[]Pattern%20Searchingpage1category[]Pattern%20Searching

int patterMatching(string text, string pattern){

    // self explanatory
    int n = text.length();
    int m = pattern.length();

    // first creating the prefix suffix table
    int* table = new int[m];

    table[0] = 0; // start element will always be zero
    // take 2 pointers i and j
    int i = 0; 
    int j = 1;

    // creating the table
    while(j < m){
        // if pattern matches, table[j] = i+ 1
        // and increment bith i and j
        if(pattern[i] == pattern[j]){
            table[j] = i + 1;
            i++;
            j++;
        }
        else{
            // if pattern does not match and we i is still at the start, then put table[j] = 0 and do j++
            if(i == 0){
                table[j] = 0;
                j++;
            } // this is not intuitive but this is how it should be handled when i != 0
            else if(i != 0){
                i = table[i-1];
            }
        }
    }

    // starting the traversal to search for pattern
    i = 0;
    j = 0;
    // this is O(N) algorithm as we are traversing the text only once

    while(i < n){

        // if pattern and text match, increment both i and j
        if(j < m && pattern[j] == text[i])
        {
            i++;
            j++;
        }

        // pattern fully matched, check this here, ie after incrementing i and j, 
        // as when the word is at last, it will cause error otherwise
        if(j == m){
            return i - m; // not i-m+1 as i would also be on the next character after substring has been matched
        } // following 0 based indexing

        // if however patterns are not equal, then 2 cases
        if(pattern[j] != text[i]){
            // if j == 0, that is at start of pattern increment i
            if(j == 0){
                i++;
            }
            // else we use the table to avoid losing our complete progress and help in saving time
            else{
                j = table[j-1];
            }
        }
    }

    return -1; // return this if index not found


}