

#include <iostream>

using namespace std;

int ribbon(int *arr, int n, int l)
{
	if(l == 1 || l == 0 || n == 0)
	{
		return 1;
	}

	if(arr[n-1] <= l)
	{
		return max((arr[n-1] *ribbon(arr,n,l - arr[n-1])), ribbon(arr, n-1,l));
	}
	else
	{
		return ribbon(arr, n-1,l);
	}
}

int main()
{
    int n;
	cin>>n; // length of rod

	int *arr = new int[n-1];

	for(int i = 0; i <n-1; i++)
	{
		arr[i] = i + 1;
	}

	int length = n;
	cout<<ribbon(arr, n-1, length)<<'\n';


    return 0;
}


// memoization
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;



int ribbon(int *arr, int n, int l, int t[][100])
{
	if(l == 1 || l == 0 || n == 0)
	{   
	    t[n][l] = 1;
		return 1;
	}
	
	if(t[n][l] != -1)
	{
	    return t[n][l];
	}

	if(arr[n-1] <= l)
	{
		t[n][l] =  max((arr[n-1] *ribbon(arr,n,l - arr[n-1],t)), ribbon(arr, n-1,l,t));
	    return t[n][l];
	    
	}
	else
	{
		t[n][l] = ribbon(arr, n-1,l,t);
	    return t[n][l];
	    
	}
}

int main()
{
    int n;
	cin>>n; // length of rod

	int *arr = new int[n-1];

	for(int i = 0; i <n-1; i++)
	{
		arr[i] = i + 1;
	}
    
	int length = n;
	
	int t[n][100];
	memset(t, -1, sizeof(t));
	
	cout<<ribbon(arr, n-1, length, t)<<'\n';


    return 0;
}

