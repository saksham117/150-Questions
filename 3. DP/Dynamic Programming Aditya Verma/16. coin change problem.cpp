// coin change problem is of two types
// one is maximum no of ways and the other is minimum number of coins

// we are given a coin array eg coin: [1,2,3] 
// and a sum let us say 5

// so we need to find the number of ways in which we can use the coin so that the sum is n
// the coins are unlimited


// this is a clear example of unbounded knapsack becasue
// 1) we are guven a choice whether to include the element or not
// 2) we are given a sum which we need to find(equivalent to W)
// 3) since the number if times we can take a coin are unlimited, that is why it is unbounded knapsack

// now here the weight array is matching the coin array
// in short it is a combination of two problems Subset Sum and unbounded Knapsack



int countWaysToMakeChange(int coin[], int n, int sum){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    
    int t[n+1][sum + 1];
    
    for(int i = 0; i <= sum; i++)
    {
        t[0][i] = 0;
    }
    
    
    for(int i = 0; i <= n; i++)
    {
        t[i][0] = 1;
    }
    
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j<= sum; j++)
        {
            if(coin[i-1] <= j)
            {
                t[i][j] = t[i-1][j] + t[i][j - coin[i-1]];
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
            
        }
    }
    
    return t[n][sum];


}
