// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector> // for 2D vector
#include<algorithm> // for sort()
using namespace std;

bool compare(int*arr1, int*arr2){
    // first case
    if(arr1[0] == arr2[0]){
        return true;
    }
    else{
        arr1[0] < arr2[0];
    }
}

class Info{
    public:
        int name;
        int value;
        int relevance;
        
        Info(int a, int b, int c){
            name = a;
            value = b;
            relevance = c;
        }
};

bool sortcol(Info a, Info b){
    // sorting on basis of name
    if(a.name == b.name){
        if(a.value == b.value){
            return a.relevance <= b.relevance;
        }
        else{
            return a.value < b.value;
        }
    }
    else{
        return a.name < b.name;
    }
}


int main() {
    // Write C++ code here
    // std::cout << "Hello world!";
    vector<Info> arr;
    arr.push_back(Info(1,2,3));
    arr.push_back(Info(1,2,1));
    arr.push_back(Info(1,3,3));
    arr.push_back(Info(2,1,3));
    
    sort(arr.begin(), arr.end(), sortcol);

    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i].name<<" "<<arr[i].value<<" "<<arr[i].relevance;
        cout<<'\n';
    }

    return 0;
}