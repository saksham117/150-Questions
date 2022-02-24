// the previou code need to be optimized a little more
// it wont pass all tese cases in all platfroms

// so we only checked t[i][j]

// it might be possible that t[i][j] has not been solved and instead one or both of t[i][k] and t[k+1][j] would have been solved

if(t[i][k] != -1)
{
	left = t[i][k];
}
else
{
	left = solve(s, i, k);
}

if(t[k+1][j] != -1)
{
	right = t[k+1][j];
}
else
{
	right = solve(s, k+1, j);
}

tempans = 1 + left + right;

// write this instead of

tempans = 1 + solve(s,l,k) + solve(s, k+1, r);
