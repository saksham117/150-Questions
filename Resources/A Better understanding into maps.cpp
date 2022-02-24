#include<bits/stdc++.h>
#include <iostream>
// #include<unorderes_map>
using namespace std;

// this works perfectly fine
int main() {
    // Write C++ code here
    map<int, vector<int>> hashMap;
    hashMap[0].push_back(1);
    hashMap[0].push_back(2);
    
    hashMap[1].push_back(11);
    
    for(auto it: hashMap){
        for(auto val: it.second){
            cout<<val<<'\n';
        }
    }
    

    return 0;
}

// this too works completely fine 
#include<bits/stdc++.h>
#include <iostream>
// #include<unorderes_map>
using namespace std;

int main() {
    // Write C++ code here
    map<int, map<int,vector<int>>> hashMap;
    hashMap[0][0].push_back(1);
    hashMap[0][0].push_back(111);
    hashMap[0][1].push_back(2);
    
    hashMap[1][2].push_back(11);
    
    for(auto it: hashMap){
        for(auto it2: it.second){
            for(auto val : it2.second)
            {
                cout<<it.first<<" "<<it2.first<<" "<<val<<'\n';
                // printing x,y,value
            }
        }
    }
    

    return 0;
}