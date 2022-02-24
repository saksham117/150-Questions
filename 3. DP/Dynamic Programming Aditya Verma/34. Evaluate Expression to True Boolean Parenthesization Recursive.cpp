// so as input, we shall be given  a string
// the string can contain the following characters T F , &, |, ^
// with each of these characters representing true, false, and, or and Xor
// so the string will be made from the following 5 things

// we need to figure out, where we need to place these brackets so that final string outputs to true
// so the total number of ways in which the brackts can be placed is to be returned as the asnwer

// so this is a question of mcm, becasue we have to choose a starting index and an ending index and 
// in between the two we need to place the brackets
// aslo k can only be placed at operators, not on true or false

// so if i find a valid postion for k, after that we need to do k+2, coz at k+1 either T or F will be present


// now lets come to the four steps
// 1) choose values of i and j
/// i = 0 and j = s.length() -1

// before discussing the base condition let us see another thing
// to say if expr1 ^ expr2 is Xor or not
// it can be the case that expr1 is T and expr2 is false or vice versa
// so if the total number of ways in which expr1 is t(n) and expresion 2 is false(m)
// then total number of ways in which the complete expression will be false will be n * m
// so we need another parameter to decide that whether the subproblem we wnat, should it be evaluated as true or as false

int solve(string s, int i, int j, bool isTrue)
{
// 2) base condition
// here k will be placed at an operator
// so the two partiton will be from i to k-1 and other from k+1 to j
// remeber i and j will only be placed on characters

// now

if ( i > j) // empty string
{
	return false;
}

if (i == j)  // single character
{
	if (isTrue == true)
	{
		return s[i] == true; 
	}
	else
	{
		return s[i] == false;
	}

}

// loop
// k will start at i +1
// will go till j-1
// and we shall do k + 2

int ans = 0;

for(int k = i+1; k <=j-1; k = k+2)
{
	int leftTrue = solve(s, i,k-1,true);
	int leftFalse = solve(s, i,k-1,false);

	int rightTrue = solve(s, k+1,j,true);
	int rightFalse = solve(s, k+1,j,false);


	if(s[k] == '&')
	{
		if (isTrue == true)
		{
			ans = ans + leftTrue*rightTrue;
		}
		else
		{
			ans = ans + leftFalse*rightTrue + rightFalse*leftTrue + leftFalse*rightFalse;
		}
	}
	else if(s[k] == '|')
	{
		if (isTrue == true)
		{
			ans = ans + leftTrue*rightTrue + leftFalse*rightTrue + rightFalse*leftTrue;
		}
		else
		{
			ans = ans + leftFalse*rightFalse;
		}
	}
	else
	{
		if (isTrue == true)
		{
			ans = ans +  leftFalse*rightTrue + rightFalse*leftTrue;
		}
		else
		{
			ans = ans +leftTrue*rightTrue + leftFalse*rightFalse;
		}
	}

}

return ans;

}



// memoization

// in this case he matrix formed will be a 3d matrix as 3 varaibes are cahnging which are i, j and istrue
// i and j can range from 0 to s.length() and istrue can be t or false
// so matrix dimension will be t[n+1][n+1][2]

// this is one way
// other thing that we could do is make a map

// so key will be "ijistrue" 
// value will be the count

// rest of the procedure I know and is same across all questons
