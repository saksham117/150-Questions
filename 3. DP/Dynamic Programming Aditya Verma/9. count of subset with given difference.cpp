// we are given an array 
// say array is [1, 1, 2, 3] 
// we need to divide them into two such subsets that their differnce is a given number, say 1 and give a count of such subsets

// so again we have a complex problem and we need to break it down to a simpler problem
//  which problem does it draw similarity too
// i guess it is the subset sum problem

// so let us say sum of the array given is range and let the required difference be d
// so if sum of subset 1 is s1 and sum of subset 2 is s2
// then s1 - s2 = d
// or s1 - (range - s1) = d
// or s1 = (range + d)/2

// so we need to find all such subsets whose sum is (range + d) /2
// if d is odd, then the range has to be odd for us to get an answer
// if range is odd, then s1 has to be even and s2 odd or vice vers
// and ifference of odd and even is always odd
// if d is even, then the range has to be even for us to get an answer

int countSubsetSum(int *arr, int n, int sum)
{
	t[n+1][sum + 1];

	// initiliaztion
for(int i = 0; i <= n; i++)
{
	for(int j = 0; j<= sum; j++)
	{
		if(i == 0)
		{
			t[i][j] = 0;
		}

		if(j == 0)
		{
			t[i][j] = 1;
		}
	}
}

// iterative step
for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= sum; j++)
		{
			if(arr[i] <= sum)
			{
				t[i][j] = ( t[i-1][j - arr[i]] ) + ( t[i-1][j]);
			}
			else
			{
				t[i][j] = t[i-1][j];
			}
		}
	}

	return t[n][sum];
}



int countDiff(int *arr, int n, int diff)
{
	int sum = 0;

	for(int i = 0; i <n; i++)
	{
		sum += arr[i];
	}

	if( d%2 == 0 and sum%2 == 0)
	{
		int s1 = (d + sum)/2;
		return countSubsetSum(arr, n, s1);
	}
	else if( d%2 != 0 and sum != 0)
	{
		int s1 = (d + sum)/2;
		return countSubsetSum(arr, n, s1);
	}
	else{
		return 0;
	}

}