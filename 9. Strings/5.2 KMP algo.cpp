// both you wont understand 

// TUSHAR ROY
// Knuth Morris Pratt (KMP) Algorithm 
// It is another pattern matching algorithm
//                 0 1 2 3 4 5 6 7
// suppose text is a b c b c g l x (length = m)

//            0 1 2 3
// pattern is b c g l (length == n)

// and we need to tell whether this pattern exists or not in the above substring
// so brute firce way dies it in time O(mn)

// KMP can do it im O(m+n)
// lets understand via an example
// text : abcxabcdabxabcdabcdabcy
// ptrn : abcdabcy
// tak i for text and j for pattern

// compare i and j 


// Knuth Morris Pratt (KMP) Algorithm 
// It is another pattern matching algorithm

// lets suppose our text is  a b c d e f g h
//                           1 2 3 4 5 6 7 8

// and pattern is d e f
//                1 2 3

// if such a pattern exists, find out its index!


// Brute Force: 
// Takes O(NM) time
// we basically try to match each character of pattern and text
// if they match, continue matching
// else move the pointer of the text by 1 position


// Optimize it using KMP
// There is some terminology used in KMP Algorithm 
// prefix and suffix

// so if pattern is a b c d a b c
// then

// prefix: a, ab, abc, abcd, abcda, abcdab, abcdabc (all strings starting with a : str[0])

// suffic c, bc, abc, dabc, cdabc, bcdabc, abcdabc (all string starting with c : str[n-1])

//  so the idea of KMP is that is there any prefix which is the same as a suffix
// in our case, we have one possible such substring which is "abc"

// Or what other condition we can check
// Is the beginning of the pattern, appearing anywhere else again in the later part of the string or not

// For a pattern we generate a PI table or longest prefix same as some suffix
//  1 2 3 4 5 6 7 8 9 10
//  a b c d a b e a b f
//  0 0 0 0 1 2 0 1 2 0  : PI table. Where all the pattern is repeating


// Working
// a b a b c a b c a b  a  b  a  b  d  String
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

// Pattern
// a b a b d

// Algorithm
// 1 Prepare a PI table for the pattern

// Pattern
// 1 2 3 4 5
// a b a b d
// 0 0 1 2 0 

// we start i from 1( 1 based indexing), bu start j from 0(ideaaly should have started from 1, by 0 makes it simpler)
// compare text[i] with pattern[j+1]
// So if the letters continue to match, move both i and j pointers ahead
//  if they do not match, then move index j to PI[J]
// for example in our case mismatch will occur when j is at 4
// so don move j back to 0, move it back to 2(PI[j])

// if ater all this j goes back to 0
// start j from 0 and i becomes i+1 (i wont backtrac to 1)

