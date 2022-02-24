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

string removeConsecutiveDuplicates(string str) 
{
    //Write your code here
    int i = 0;
    
    while(i < str.length() - 1){
        
        if(str[i] != str[i+1]){
            i++;
            continue;
        }
        else{
            int j = i+1;
            while( j+1 < str.length() && str[j] == str[j+1]) j++;
            str.erase(i+1, j-i);
        	i = i+1;
        }
    }
    
    return str;
}