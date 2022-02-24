// Brute force: Use hashmap or count array

// Optimal: Use concept of sum of naturanl numbers and sum of square of natural numbers
// x will be missing and y will be repeating
// calaculte sum and sum of square og given array and also what is should be

// subtracting the twio we will get x-y and x+y
// solve for x and y
// just be carfeul of integre overflow


class Solution{
public:
    int *findTwoElement(int *A, int n) {
        // code here
    long long int len = n;
    long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6; // calculating ideal sum of  first N
    // natural numbers and sum of squares of first n natural numbers

    long long int missingNumber=0, repeating=0;
      
    for(int i=0;i<n; i++){
       Sum_N -= (long long int)A[i]; // at the end of for loop this will result in x-y
       Sum_NSq -= (long long int)A[i]*(long long int)A[i]; // at the end of for loop this will result in x^2-y^2
    }
      
    missingNumber = (Sum_N + Sum_NSq/Sum_N)/2; // this will give x
    repeating= missingNumber - Sum_N; // this will give y
    
    int* result = new int[2];
    result[0] = repeating;
    result[1] = missingNumber;
    
    return result;
    
    }
};

// Another optimal approach would be to use XOR property
// Intially assign xor as 0
// then linearly iterate over the array, xoring the terms

// eg arr = 4,3,6,2,1,1 
// so after first xor we get 3

// now take that and xor it(3) with 1,2,3,4,5,6 (the perfect array)
// so now we get 4

// this basically represent xXORy where x is repeating and y is missing number or vice versa
// as this is (4^3^6^2^1^1) ^ (1^2^3^4^5^6)
// so common elements will get cancelled and we will have(1^5) which is 4
// so we havent got x and y, but we now xXORy

// weird approach. Need to see again and again to understand
// see this https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/