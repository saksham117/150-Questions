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
    bool backspaceCompare(string s, string t) {
        
        int i = 0;
        while(i < s.length()){
            if(s[i] == '#'){
                if(i == 0){
                    s.erase(i,1);
                }
                else{
                    s.erase(i-1,2);
                    i = i-1;
                }
            }
            else{
                i++;
            }
        }
        
        int j = 0;
        while(j < t.length()){
            if(t[j] == '#'){
                if(j == 0){
                    t.erase(j,1);
                }
                else{
                    t.erase(j-1,2);
                    j = j-1;
                }
            }
            else{
                j++;
            }
        }
        cout<<s<<" "<<t;
        
        if(s.compare(t) == 0){
            return true;
        }
        else{
            return false;
        }
        
    }
};