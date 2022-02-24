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
// very similar concept to sort a stack

void reverse(stack<int> &s, int element){
    if(s.size() == 0){
        s.push(element);
    	return;
    }
    
    int top = s.top();
    s.pop();
    reverse(s,element);
    s.push(top);
    return;
}

void reverseStack(stack<int> &s) {
    // Write your code here
    if(s.size() == 0 || s.size() == 1){
        return;
    }
    
    int element = s.top();
    s.pop();
    reverseStack(s);
    reverse(s,element);
    return;
}