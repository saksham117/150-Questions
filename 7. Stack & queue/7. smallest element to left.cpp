#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

// question 1
// NEXT smallest ELEMENT
// very similar question
// jsut start from left
// conditions are reversed

class Solution{
    public:
    vector<long long> nextSmallestElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> s;
        vector<long long> output;

        s.push(arr[0]);
        output.push_back(-1);
        
        for(int i = i; i < n; i++)
        {
            if(arr[i] >= s.top())
            {
                output.push_back(s.top());
                s.push(arr[i]);
            }
            else
            {
                while(!s.empty())
                {
                    if(arr[i] < s.top())
                    {
                        s.pop();
                    }
                    else 
                    {
                        output.push_back(s.top());
                        s.push(arr[i]);
                        break; 
                    }

                }

                if(s.empty())
                {
                    s.push(arr[i]);
                    output.push_back(-1);
                }
            }
        }

        return output;
        
    }
};


// Intervew Bit Code
vector<int> prevSmaller(vector<int> &A) {
        stack<int> s;
        vector<int> output;

        s.push(A[0]);
        output.push_back(-1);
        int n = A.size();

        for(int i = 1; i < n; i++)
        {
            if(A[i] > s.top())
            {
                output.push_back(s.top());
                s.push(A[i]);
            }
            else
            {
                while(!s.empty())
                {
                    if(A[i] <= s.top())
                    {
                        s.pop();
                    }
                    else 
                    {
                        output.push_back(s.top());
                        s.push(A[i]);
                        break; 
                    }

                }

                if(s.empty())
                {
                    s.push(A[i]);
                    output.push_back(-1);
                }
            }
        }

        return output;
}