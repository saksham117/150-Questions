// we will be given two strings and what we will be asked is whether string1 is a subsequence of string 2 or not
// return true ot false

// eg str1 = "AXY"
// eg str2 = "ADXCPY"

// SO HERE ANSER IS true

// so what i belive is that if we apply lcs to this
// then if the lenght of lcs is same as the length of our given pattern(str1)
// then asnwer is true
// this is becasue str1 will be present in str2 if it is the lcs of str2

// so this is simple

// Recursive C++ program to check if a string is subsequence of another string 
#include<iostream> 
#include<cstring> 
using namespace std; 
  
// Returns true if str1[] is a subsequence of str2[]. m is 
// length of str1 and n is length of str2 
bool isSubSequence(char str1[], char str2[], int m, int n) 
{ 
    // Base Cases 
    if (m == 0) return true; 
    if (n == 0) return false; 
  
    // If last characters of two strings are matching 
    if (str1[m-1] == str2[n-1]) 
        return isSubSequence(str1, str2, m-1, n-1); 
  
    // If last characters are not matching 
    return isSubSequence(str1, str2, m, n-1); 
} 
  
// Driver program to test methods of graph class 
int main() 
{ 
    char str1[] = "gksrek"; 
    char str2[] = "geeksforgeeks"; 
    int m = strlen(str1); 
    int n = strlen(str2); 
    isSubSequence(str1, str2, m, n)? cout << "Yes ": 
                                     cout << "No"; 
    return 0; 
} 