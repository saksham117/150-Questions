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

 int solution(string str, int k) {
	// write your code here
    int i = 0, j = 0;
    int count = 0;
    unordered_map<char, int> freqMap;

    int n = str.length();

    while(j < n){

        freqMap[str[j]]++;

        if(freqMap.size() <= k){
            j++;
        }
        else if(freqMap.size() > k){
            while(freqMap.size() > k){

                count += j-i;
                freqMap[str[i]]--;

                if(freqMap[str[i]] == 0){
                    freqMap.erase(str[i]);
                }

                i++;
            }

            j++;
        }
    }

    int m = j-i;
    int last = (m*(m+1))/2;
    count += last; // this is when j becomes greater than n and there is still i 
    // to jitne remaining hai
    // unke kitne combination ban sakte hain
    // yeh voh hai
    // baiscally pehle elemet in sab main would be taken m times, agla m-1 times and so on 
    // take examples and you shall see why
    
    return count;

}

int main() {
    string str;
    int k;
    cin >> str >> k;
	cout << solution(str,k);
}