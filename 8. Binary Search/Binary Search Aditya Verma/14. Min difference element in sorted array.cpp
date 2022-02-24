// We have already done this q previously, but it has been asked in such a way
// That we often fail to deduce ki aisa code bhi lag jaayega yahan!!


// We will be given a sorted array
// and we will be given a key
// we need to find an element in the sorted array
// such that absolute difference btw key and that element is minimum

// eg arr = [4,6,10] , key = 7
// ans will be 6 


// So I got it
// find floor and ceil of the key
// return min of (key - floor) and (ceil - key)



// OR OR OR OR
// Interesting observation by Aditya
// Do normal binary search
// if key is found, then that is the answer
// if key is not found, that is we will scan complete array and we will get -1 as the key search
// So in that case ans will be index low or high, whichever results in the minimmum absolute difference between key and them

// This is because in binary search, we keep on reducing our search space, and we terminate it after we have exhausted all search
// spaces. low > high and those two indices will be pointing to elements which were closest to our given key! Always

// take an example and you shall see
// arr = [1,3,8,10,15], key = 12
