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

// This is a very important problem
// If you solve this, then you will be able to solve basically any problem involving XOR and array

// Brute Force
// Take two for loops and iterate one by one and see if that subarray gives the required XOR 

// Optimal:
// Using concept of largest subarray with zero sum
// https://takeuforward.org/data-structure/count-the-number-of-subarrays-with-given-xor-k/

// Prefix xor and map

// Intuition: The main idea is to observe the prefix xor of the array. 

// Prefix Xor is just another array, where each index contains XOR of all elements of the original array starting from index 0 up 
// to that index. In other words
// prefix_xor[i] = XOR(a[0], a[1], a[2],……,a[I])

// Once we have made the prefix xor array, we observe a fact: (P > Q)
// P = xor(a[0], a[1], a[2],……, a[q], a[q+1],….., a[p])
// Q = xor(a[0], a[1], a[2],……, a[q])

// Therefore,
// P^Q = xor(a[q+1],….., a[p]) = M                                
// So, now we understand that from the prefix xor array when we XOR two elements at different indices we get the 
// xor of the elements (in the original array) that were between those indices.

// Let’s say we did XOR(P, B) and we got Q (B is the integer given in question). What does this mean?
// This means that the subarray between q and p is having xor = B. To understand this we just use simple equations:
// P^B = Q
// => P^B^P = Q^P
// => B = Q^P  

// And we already know by fact 1 that Q^P will give xor of all elements between q and p. Therefore, the subarray between q and p 
// has xor = B.

// Suppose we did XOR(P, B) and we got Q (B is the integer given in question). But there is more than one Q before p.
// In this case, there are two subarrays that have XOR = B. Subarrays between q1 to p and q2 to p. 

// IMP NOTE: although we talk about prefix xor “array”, it should be noted that at a time we need only one element of this array.
//  Hence, we can just use a variable to maintain the prefix xor. 

// Approach: We need to traverse the array while we maintain variables for current_perfix_xor, counter, 
// and also a map to keep track of visited xors. This map will maintain the frequency count of all previous 
// visited current_prefix_xor values. If for any index current_prefix_xor is equal to B, we increment the 
// counter. If for any index we find that Z is present in the visited map, we increment the counter by 
// visited[Z] (Z=current_prefi_xor^B). At every index, we insert the current_prefix_xor into the visited map with its frequency.

class Solution{
    public:
    int solve(vector<int> &A, int B) {
    unordered_map<int,int>visited;
    int cpx = 0;
    long long c=0;
    for(int i=0;i<A.size();i++){
        cpx^=A[i];
        if(cpx==B) c++;
        int h = cpx^B;
        if(visited.find(h)!=visited.end()){
            c=c+visited[h];
        }
        visited[cpx]++;
    }
    return c;
}
};
