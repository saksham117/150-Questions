// now we shall discuss the unbounded knapsack problem 
// along with this we shall see 4 problems that are based on this
// 1) Rod cutting problem
// 2) Coin change 1
// 3) con change 2
// 4) maximum ribbon cutting

// so if suppose we are given an array of items with its properties like weight and value
// then in 0- 1knapsack, if we had considered an element once(whether to take it or not), we didn't used to see that again
// but over here it is the case that we can select multiple occurences of the same element

// in 0 -1 knpasack we used to either take an element or not take an element
// and after that we did not used to go back to that element
// we used to consider the elemnt processed


// but in unbounded knapsack, we again have two choices
// if we do not select it, then we consider it processed and do not come back to it
// if we select it, then we do not consider it processed, we can come back to it


// now let us come to the code
// summary no means no
// if yes, then again answer can be yes
// but no is no

// initialization remains the same as 0-1 knapsack

int unboundedKnapsack(int wt[], int val[], int W, int n)
{
// intitialization
 for(int i = 0; i < n + 1; i++)
 {
 	for(int j = 0; j < W +1; j++)
 	{
 		if(i == 0 || j == 0)
 		{
 			t[i][j] = 0;
 		}
 	}
 }

 // filling
for(int i = 1; i < n + 1; i++)
{
	for(int j = 1; j < W + 1; j++)
	{
		if(wt[i - 1] <= j)
		{
			t[i][j] = max( val[i-1] + t[i][j - wt[i-1]], t[i-1][j]); // just this much differnce, when we selcet the element 
                                                                    // we do not do n-1 (or i-1)
		}                                                           // we can again consider it
		// again it is difficult t think dp solution straigaway. So first always go for recursive one
		// dp apne aap jhakk maar ke ho jayega
		else
		{
			t[i][j] = t[i-1][j];
		}
	}
}

return t[n][W];

