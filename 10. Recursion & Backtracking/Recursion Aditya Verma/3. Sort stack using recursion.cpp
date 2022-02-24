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

//The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};


/* The below method sorts the stack s 
you are required to complete the below method */
void helper(stack<int>& s, int element){
    
    if(s.size() == 0){
        s.push(element);
        return;
    }
    
    if(element > s.top()){
        s.push(element);
        return;
    }
    
    int top = s.top();
    s.pop();
    helper(s,element);
    s.push(top);
    return;
}
void SortedStack :: sort()
{
   //Your code here
   if(s.size() == 1){
       return;
   }
   
   int element = s.top();
   s.pop();
   sort();
   
   if(element >= s.top()){
       s.push(element);
       return;
   }
   else{
       helper(this->s, element);
       return;
   }
}