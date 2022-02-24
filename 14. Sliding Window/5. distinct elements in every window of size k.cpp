#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>
#include<map>

using namespace std;

// from striver sheet

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int> output; 
        unordered_map<int, int> freq;

        for(int i = 0; i < k; i++){
            if(freq.count(A[i] == 0)){
                freq[A[i]] = 1;
            }
            else{
                freq[A[i]] += 1;
            }
        }

        output.push_back(freq.size());
        int count = freq.size();

        for(int i = k; i < n; i++){
            freq[A[i-k]] -= 1;
            if(freq[A[i-k]] == 0){
                count -= 1;
            }

            if(freq.count(A[i]) == 0 || freq[A[i]] == 0){
                freq[A[i]] = 1;
                count+=1;
            }
            else{
                freq[A[i]] += 1;
            }

            output.push_back(count);
        }

        return output;
    }
};