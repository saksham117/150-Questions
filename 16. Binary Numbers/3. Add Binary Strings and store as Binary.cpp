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
    string addBinary(string a, string b) {
        
        if(a.length() < b.length()){
            string t = a;
            a = b;
            b = t;
        }
        
        cout<<a<<" "<<b<<'\n';

        int i = a.length() - 1;
        int j = b.length() - 1;

        string ans="";
        int carry = 0;

        while(i >= 0 && j >= 0){

            int num1 = (int)(a[i] - '0');
            int num2 = (int)(b[j] - '0');

            if(num1 + num2 + carry == 3){
                ans = to_string(1) + ans;
                carry = 1;
            }
            else if(num1 + num2 + carry == 2){
                ans = to_string(0) + ans;
                carry = 1;
            }
            else{
                ans = to_string(num1 + num2 + carry) + ans;
                carry = 0;
            }

            i--;
            j--;
        }

        while(i >= 0){
            int num1 = (int)(a[i] - '0');
            if(num1 + carry == 2){
                ans = to_string(0) + ans;
                carry = 1;
            }
            else{
                ans = to_string(num1 + carry) + ans;
                carry = 0;
            }

            i--;
        }

        if(carry == 1){
            ans = to_string(1) + ans;
            cout<<"entered here"<<'\n';
        }

        return ans;
    }
};