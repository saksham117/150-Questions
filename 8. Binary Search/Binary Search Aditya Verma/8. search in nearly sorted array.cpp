// Nearly sorted means, that an element which was supposed to be at ith position can be at ith, or (i-1)th or (i+1)th index

// so the problem is fairly simple
// apply the same binary serach
// but now suppose mid is index i
// so we will check i, i-1, i+1
// if found, return
// else if key less tha mid
// end = end -2
// else
/// start = start + 2

// also keep checks ki mid-1 doessnt become less than 0 while checking if arr[mid-1] == key
// or mid + 1 becomes greter than n 



