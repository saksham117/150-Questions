// Its a pattern/string matching algorithm

// So the question is that a string of text is given and we need to tell whether a particular  pattern is present or not.

// text : 1 2 3 4 5 6
//        a a a a a b

// pattern: 1 2 3 
//          a a b 

// BRUTE FORCE
// So the brute force method implies that we check each and every alphabet. But we do not want to do that 

// So is it possible to convert the text/ pattern into some numeric value. Some single value which we can easily compare

// so now associate a number with each alphabet. for now we are taking easy and simple numbers to just keep things simpe

// for example for a : 1
//                 b : 2
//                 c : 3
// and so on 

// Now add up the values in the pattern
//  for a a b is 1 + 1 + 2 = 4
// this value I will call as hash code
// and the function of obtaining this hash is called hash function (here gash function is simple addition operation)


// Lets say size of pattern is n and that of text is m 

// So go to first m characters, apply the hash function to them
// if equal to our hash code, return true. else slide by one and keep on checking . This sliding is also called 
// rolling hash function. 
// Once we get a match, confirm whether pattern is actually correct or not 

// Also to save time what we can do is once we have obtained hash of first m characters,
//  for next window add up m+1 and subtract first value of previous window


// HOWEVER THE DRAWBACK OF THIS IS THAT
// If the string is such that hash code matches for many values, but string is not matching, then a lot of time would be wasted. 

// So the problem is that our hash code is too simple. we need to change that!!
// There are multiple collisions. This basically means that may different strings have same hash code 
// These cases are also called spurios hits
// So time complexity in this case, the inefficeint approach goes from theta(n-m+1) to theta(nm)

// ACTUAL ALGORITHM
// so for calculating the hash of m characters what we can do is multiply the alphabet number with power of 10

// for example for pattern m  = dba

// hash = 10^2*4 + 10^1*2 + 10^0*1
// so highest power will br 10^m-1

// so now to ease the calculation what we can do is subtract the first term, multiply the remaining terms by 10 and then
//  add the new term.
// if after hashing the values do become large, we can mod them, with suppose say the maximum possible Integer 


/* Following program is a C++ implementation of Rabin Karp  
Algorithm given in the CLRS book */
#include <iostream> 
using namespace std; 
  
// d is the number of characters in the input alphabet  (we are assuming the all ASCII characters )
#define d 256  
  
/* pat -> pattern  
    txt -> text  
    q -> A prime number  
*/
void search(char pat[], char txt[], int q)  
{  
    int M = strlen(pat);  
    int N = strlen(txt);  
    int i, j;  
    int p = 0; // hash value for pattern  
    int t = 0; // hash value for txt  
    int h = 1;  // this h is very important
    // basically represents the ighest value whiich we will have
    // needed when we need to subtract the term and add the new term
  
    // The value of h would be "pow(d, M-1)%q"  
    for (i = 0; i < M - 1; i++)  
        h = (h * d) % q;  
  
    // Calculate the hash value of pattern and first  
    // window of text  
    for (i = 0; i < M; i++)  
    {  
        p = (d * p + pat[i]) % q;  
        t = (d * t + txt[i]) % q;  
    }  
  
    // Slide the pattern over text one by one  
    for (i = 0; i <= N - M; i++)  
    {  
  
        // Check the hash values of current window of text  
        // and pattern. If the hash values match then only  
        // check for characters on by one  
        if ( p == t )  
        {  
            /* Check for characters one by one */
            for (j = 0; j < M; j++)  
            {  
                if (txt[i+j] != pat[j])  
                    break;  
            }  
  
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]  
            if (j == M)  
                cout<<"Pattern found at index "<< i<<endl;  
        }  
  
        // Calculate hash value for next window of text: Remove  
        // leading digit, add trailing digit  
        if ( i < N-M )  
        {  
            t = (d*(t - txt[i]*h) + txt[i+M])%q; // if base is 10 (this means) and pattern is ccaa (where we now need to go to caa)
            // ((3*10^2 + 3^10^1 + 1^10^0) - 3*10^2) * 10 + 1*10^0
  
            // We might get negative value of t, converting it  
            // to positive  
            if (t < 0)  
            t = (t + q);  
        }  
    }  
}  
  
/* Driver code */
int main()  
{  
    char txt[] = "GEEKS FOR GEEKS";  
    char pat[] = "GEEK"; 
        
      // A prime number  
    int q = 101;  
      
      // Function Call 
      search(pat, txt, q);  
    return 0;  
} 


