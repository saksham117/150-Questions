// you will be giben two strings a nad b, and as output you neeed to return tru ot false
// and the question is that are a and b scrambled string of each other or not

// so what do you mean by a scrambled string
// so we need to break down the string into a binary tree
// and secondly ,none of the childs should be empty
// finally the leaf ndes should contin single characters
// there cant be more than one character in them, and also how to divide the string into smaller parts is your choice
// any of the ways is possible

// now in the non leaf nodes, we can perform swapping, zero or more
// so if tree us
  gr
 / \
g   r

// after swapping it will be

  rg
 / \
r   g

	great
	/   \
   gr    eat
   /\     /\
  g  r   ea t
         /\
        e  a           


	rgeat
	/   \
   rg    eat
   /\     /\
  r  g   ea t
         /\
        e  a


// so now we can say that great and rgeat are sceambled strings

// this is just ine of the possible ways to separate out great
// it could even be g and reat
// or gr and eat
// or grea and t

// so a partition can be made at all these different indices

// so here i can vary from i = 1
// and j will go till last index (length -1)

// so we can see that this is a MCM problem

// so what choice do we have, 
// at a given position we can either swap or we can not swap

// if swap occurs at i, then lets say string gets divides onto s1 an s2
// and then there is the other string b
// we shall see that whetehr the first s2 characters of b and s2 are scrambled or not
// and if the last s1 characters of b and s1 is scrambled or not

// if swappinf does not occur and string is divides as s1 ND S2
// we shall see that whetehr the first s1 characters of b and s1 are scrambled or not
// and if the last s2 characters of b and s2 is scrambled or not

// eg great and ategr
// split as gr and eat


bool solve(str a, str b)
{
	// in substr, first argument is starting index and the other is the length os string
	// case 1 when swapping happens
	if(solve(a.substr(0,i), b.substr(n-1, i)) == true && solve(a.substr(i,n-i), b.substr(0,n-i)) == true)
	{

	}

	// case 2 when swapping does not happen
	if(solve(a.substr(0,i), b.substr(0, i)) == true && solve(a.substr(i,n-i), b.substr(i,n-i)) == true)
	{
		
	}

	// if any of the above cases is true, then the asnswer will be scranlled string

}



bool solve(str a, str b)
{
	// base case
	// if both are of different length, then they cannot be scrambled strings

	if(a.length() != b.length())
	{
		return false;
	}

	// if both strings are empty, return true
	if(a.length()== 0 && b.length() == 0)
	{
		return true;
	}

	// if both strings turn out to be equal, (equal strings are also scrambled strings)  then also we need to stop and return true
	if(a.compare(b) == 0)
	{
		return true;
	}

	if(a.length() <= 1)
	{
		return false;
		// also 1 because had they been equal and only one character was there, above statement would have returned true
	}

	int n = a.length(); // both have same lenght

	bool flag = false;

	for(int i = 1; i <= n-1; i++)
	{
		if((solve(a.substr(0,i), b.substr(n-1, i)) == true && solve(a.substr(i,n-i), b.substr(0,n-i)) == true) || solve(a.substr(0,i), b.substr(0, i)) == true && solve(a.substr(i,n-i), b.substr(i,n-i)) == true )
		{
			flag = true;
			break;
		}
	}

	return flag;



}

// memoization

// over here again we shall use a map
// agar map main value preesent hai to return from there
// if not then calculate the subtrree
// and after calculating the subtree store it in the map

unordered_map<string, int> ourMap;

kwy will be of type "a" + " " + "b"
value will be 0 or 1
