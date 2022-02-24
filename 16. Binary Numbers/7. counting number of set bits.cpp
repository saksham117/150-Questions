// Online C++ compiler to run C++ program online
#include <iostream>
// #include<bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n = 63;
    int count = 0;
    while(n > 0){
        if(n&1){
            count++;
        }
        
        // right shift by 1
        n = n>>1;
    }
    
    cout<<count<<'\n';

    return 0;
}