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

// Given the total number of persons n and a number k which indicates that k-1 persons are 
// skipped and kth person is killed in circle in a fixed direction.

// The task is to choose the safe place in the circle so that when you perform these operations 
// starting from 1st place in the circle, you are the last one remaining and survive.

// Once kth person is killed
// new count for k is started from ondex k+1

// so simple problem
// coded on own
// once you understand the problem, code becomes quite easy
// learnt that direct ibh technique is involved when there are no choices
// when choices arise, you can use the recursive tree method

class Solution
{
    public:
    char helper(int k, string circle, int index){
    
        // base case
        if(circle.length() == 1){
            return circle[0]; // value of string will represent the position
        }
        
        index = (index + (k-1)) % circle.length(); //new index which will be deletd or killed
        circle.erase(index,1); // killing the person
        
        return helper(k,circle,index); // send the updated index and recur for the solution
        
    }
    
    int josephus(int n, int k)
    {
       //Your code here
      string circle = "";
   
//   creating a circle where starting cgar is 1, then 2 and so on till n
       for(int i = 0; i < n; i++){
           circle += (i+1);
       }
       
       int index = 0; // where we will start our killing
       
       return helper(k, circle, index);
    }
};