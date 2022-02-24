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
#include<sstream>

using namespace std;


// i implemented this using stringstream
class Solution {
public:
    string reverse(string str){
        int low = 0;
        int high = str.length() - 1;
        
        while(low < high){
            swap(str[low], str[high]);
            low++;
            high--;
        }
        
        return str;
    }
    string reverseWords(string s) {
        
        stringstream ss(s);
        string ans = "";
        
        string word = "";
        while(ss >> word){
            
            // string reversedStr = reverse(word);
            if(ans == ""){
                ans = word + ans;
            }
            else{
                ans = word + " " + ans;
            }
        }
        
        return ans;
        
    }
};

// another approach i can think of is using the replace function present in c++
// first remove all extra spaces, till there is only one space btw each word and 0 in start and at end
// then take a pointer at start, take another pointer at end and swap them
// i++ and j--

// Is tougher than it looks

// 1 Brute Force
// Iterate over the array, as soon as you enounter a word, push it into the array
// Skip the whitespace
// Pop from the array in reverse order

// 2 Optimal
// If I am given flexibility of inbuilt functions
// Use string stream
class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        stringstream str(s);
        string word;
        while (str >> word) // store separated words in vector
            vec.push_back(word);
        
        reverse(vec.begin(), vec.end()); // reverse vector
        
        string res;
        for (const auto &it : vec) // concatenate strings
            res+=" "+it;
        res.erase(0,1); // first place is always a space - extra
        
        return res;
    }
};

// 3) From scratch
// Reverse each word and also remove extra whitespace along the way
// Reverse the complete string

class Solution {
public:
    string reverseWords(string s) {

        int i = 0;
        int n = s.length() - 1;

        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                int 
            }
        }
        
    }
};



// 4 Can also use a stack
string reverseWords(string s) {
        if(s.size() == 0) return s;
        stack<string> stack;
        string result;
        for(int i=0; i<s.size(); i++) {
            string word;
            if(s[i]==' ') continue; //skip spaces
            while(i<s.size() && s[i]!=' ' ) { //store continuous letters into word
                word += s[i]; i++;
            }
            stack.push(word); //push word to the stack
        }
        while(!stack.empty()) {
            result += stack.top(); stack.pop();
            if(!stack.empty()) result += " ";
        }
        return result;
    }
};