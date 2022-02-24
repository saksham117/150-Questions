// so let us see the format of this
// MATRIX CHAIN MULTIPLICATION

// We will only be covering the recursive approach and then the memoized
// writing top down has no advantage and will result in confusion


// IDENTIFIACTION + FORMAT
//  you shall be given a string or an array
// so basically what happens is that we take two indices i and j
// and we take a variable k, in between the two variables i and j
// now we need to solve two subproblems, one from i to k
// and other from k+1 to j
// we shall solve them recursively and return their answer
// so initialy function call will be fun(i,j)
// from their two functin calls will be made, fun(i,k) and fun(k+1,j)
// these two functin calls will return some temporray answers
// then we need to operate on those temporary answers to generate the final answer

//format

int solve(int arr, int i, int j) // i will be close to left end index and j will be close to right end index
{
	// base condition sochne ke do tareeke hain
	// think of the smallest valid input
	// or
	// think of an invalid input

	// here we shall choose the base case from the second condition
	if( i > j ) // depending on the question, this can be different
	{
		return 0;
	}

	for(int k = i; k < j; k++)
	{
		// calculate temporary answer
		int tempans = solve(arr, i, k) + solve(arr, k+1,j);
		// there would be slight variations in this format, depending on the question itself
		//  like insted of i++, it could be i+2, or in case of solve + solve it could be solve || solve

		int ans = fun(tempans) // some function(could be min or max or somethin else)
	}

	return ans;
}
