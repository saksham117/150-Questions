// we are given an array and a target sum
// in front of every element we need to add a + or a - sign so that the sum of the array becomes the target sum
// so we need to return the numver of such combinations
// eg array = [1,1,2,3]
// target sum = 1



// if we observe carefully, the problem reduces to finding two subsets whose differnce is the given target sum
// that is count of subsets with a given sum
// like if we assign -1 +1 -2 +3
// this is equal to (1 + 3) - (1 + 2)
// so this is nothing but counting the susbets with a given differnce

// so target sum is just a complex way of asking the count the subset with a given differnce


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


// source : pinned comment under tech dose video 
// For those who has problem with test case  [0,0,0,0,0,0,0,0,1], target = 1.

// The solution doesn't consider presence of "0"s in the array. Why the output is different ?

// Because, if we have "0", then, it can have +0 and -0 and still will not effect the sum of a set. For example: Target value is = 2

// 1) {0,2} = {+0,2}, {-0,2}.  Ans: 2

// But if we increase number of 0s,

// 2) {0,0,2} = {+0,+0,2}, {+0,-0,2}, {-0,+0,2},{-0,-0,2} . Ans: 4



// So, if you observe, your answer increase by (2^number of 0s) i.e. pow(2,number of zeros).

// So, make a small change as follows:

// 1) on count of subsetsum function, 

// if(nums[i-1] > j )    => change to:  if (nums[i-1] > j || nums[i-1] == 0)

//       dp[i][j] = dp[i-1][j];

//  //make no change and put the previous value as it is in the next subproblem. (I.e. 2, in example above)

// And then at the end, you answer will be

// return (int)Math.pow(2, number of 0s) * dp[nums.length][target] ;

// Also, other cases we need to handle is:
// if (S > sum || (sum + S) % 2 != 0){ //S is target

//             return 0;

//  }