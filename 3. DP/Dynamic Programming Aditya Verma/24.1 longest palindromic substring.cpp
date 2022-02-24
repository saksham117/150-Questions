// this is a tough question
// jahan bhi string aa jaati, vahan cheezin complex ho jaati hain

// toh my approach is
// Just like we did in previous question, we can calcualte longest common substring between s and revser of s

// if the interviewer is happy with this, fine
// otherwise problems can arise in edge cases like these
// For example, SS = "caba", S'S 
// ′
//   = "abac".
// The longest common substring between SS and S'S 
// ′
//   is "aba", which is the answer.

// Let’s try another example: SS = "abacdfgdcaba", S'S 
// ′
//   = "abacdgfdcaba".

// The longest common substring between SS and S'S 
// ′
//   is "abacd". Clearly, this is not a valid palindrome.

// So in this case, what I will say is
// that for every lcs that I find as a candidate, I can see if it is of maximum length or not.

// There are much more complex approaches, but I am not going in them