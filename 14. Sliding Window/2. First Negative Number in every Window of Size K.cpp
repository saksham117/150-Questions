#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<set>
#include<map>

using namespace std;

// used the same dequeue approach told by striver in q3 where we had to find the maximum

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    
    vector<long long> output;
    deque<long long int> dq;
    int i = 0;
    int j = 0;
    
    while(j < N){
        if(!dq.empty() && j-K == dq.front()){
            dq.pop_front();
        }
        
        if(A[j] < 0){
            dq.push_back(j);
        }
        
        if(j-i+1 == K){
            if(dq.empty()){
                output.push_back(0);
            }
            else{
                output.push_back(A[dq.front()]);
            }
            
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    
    return output;
                                                 
 }