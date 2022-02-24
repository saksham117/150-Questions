
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<unordered_set>

using namespace std;

class Solution
{
	public:
		int binary_to_decimal(string str)
		{
		    // Code here.
		    int num = (int)(str[0] - '0');
		    for(int i = 1; i < str.length(); i++){
		        num = num << 1;
		        num = num | (int)(str[i] - '0');
		    }
		    
		    return num;
		}
};