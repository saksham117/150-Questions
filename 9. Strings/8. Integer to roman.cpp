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

class Solution {
public:
    const int val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    const string rom[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    string intToRoman(int N) {
        string ans = "";
        for (int i = 0; N; i++)
            while (N >= val[i]) ans += rom[i], N -= val[i];
        return ans;
    }
};

// https://leetcode.com/problems/integer-to-roman/discuss/1102775/JS-Python-Java-C%2B%2B-or-Simple-Solution-w-Explanation