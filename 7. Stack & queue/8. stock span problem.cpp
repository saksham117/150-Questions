#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

// stock span problem
// given an arr, 
//  [100 80 60 70 60 75 85]
// for each day, find the number of consecutive days that had price smaller than or equal to it

// so according to me, the problem is as simple as finding the index of the next(closest) greatest element to the left
// and subtrating that days index with that array index to obtain the array

// The below code is not optimized for space. It can be further optimized
class Solution{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<int> s;
       vector<int> output;
       vector<int> temp;
       temp.push_back(1);
       s.push(0);


    //    output.push_back(1);

       for(int i = 1; i < n; i++)
       {
           if(price[i] < price[s.top()])
           {
               temp.push_back(s.top());
               s.push(i);
           }
           else
           {
               while(!s.empty())
               {
                   if(price[i] < price[s.top()])
                   {
                        temp.push_back(s.top());
                        s.push(i);
                        break;
                   }
                   s.pop();
               }

               if(s.empty())
               {
                   temp.push_back(-1);
                   s.push(i);
               }
           }
       }

       output.push_back(1); 
       for(int i = 1; i < temp.size(); i++)
       {
           output.push_back(i - temp[i]);
       }

       return output;

    }
};