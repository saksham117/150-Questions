// Given a string str, the task is to find the lexicographically smallest string that can be formed by removing
//  at most one character from the given string. 

// Examples: 

// Input: str = "abcda"  
// Output: abca
// One can remove 'd' to get "abca" which is 
// the lexicographically smallest string possible. 

// Input: str = "aaa' 
// Output: aa

// WAS able to figure this one out

// Approach: Traverse the string and delete the i-th character at the first point where s[i]>s[i+1]. 
// If in case there is no such character then delete the last character in the string. 