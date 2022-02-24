// in the problem statement, we would be given the number of eggs
// and the number of floors
// eg e = 3 and f = 5

// we need to minimize the number of attempts in worst case

// we need to calculate the threshold floor
// lets say that the threshold floor is k
// so for all floors higher than k, the egg would break
// from others, it wont

// we need to find the minimum number of attempts to calculate this threshold floor, not the threshold floor

// we are given only those 3 eggs, and using that we need to find what is the threshold floor
// so we need to use the eggs wisely

//  if we are given only one egg, then safrest approach is to start dropping egg from floor 1,2,3 and so on
// the floor on which egg breaks, the floor just below that is the threshold floor
// However this will result in maximum number of attempts
// but q is to minimize these attempts


// so using the given eggs, we need to adopt the best stategy to find the minimum number of ways to find the threshold floor, 
// given that the scenario is a worst case scenario(worst case scenario is key egg will break from topmost or a very high floor
// if we take one egg and start dropping it from the very bottom)

// so we would be given f, but we can assume that it reprsents an array of values ranging from 1 to f
// so we can pick i at the minimm position that is index 0 or floor 1
// and we can pick j at the last index or floor f
// so now the uestion is k kahan lageayen
// so this is how it becomes an mcm problem

k = i;
k goes till j

so range of k is from 1 to f and k++


// base case
if (e == 1) // no of eggs are 1, we shall try from the bottom and the worst case answer would be f
{
	return f;
} 

if (f <= 1) // if no of floors are less than or eqaul to 1, then in one go itself we can tell whether it is threshold floor or not
{
	return 1;
}


// now we have two choices, depemding on which floor we are, whether from that the egg breaks or not

// egg breks
solve(e-1, k-1)

// does not break
solve(e, f-k)


// first parameter represent the number of eggs left and the second represent the number of floors we now need to explore


int solve(int e, int f)
{
	if(e == 1)
	{
		return f;
	}

	if(f <= 1)
	{
		return f;
	}

	int mn = INT_MAX;

	for(int k = 1; k <=f; k++)
	{
		int temp = 1 + max(solve(e-1,k-1), solve(e, f-k)); // max becoz we need to find out the worst case

		if (temp < mn)
		{
			mn = temp;
		}
	}

	return mn;

}


// MEMOIZATION
// initilaize t by -1
t is of size[e+1][f+1]

// rest we know where and when to change it

// further optimization
 // just like we did in palindrome vaala quetion
