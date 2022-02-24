// You will be given 3 poles (source, helper, destination)
// and N disks
// You need to place all disks located on source pole, placed in a fashion such that smallest disc is at top and largest at bottom
//  and move it to destination pole, under the following conditions 
    
    // 1) You can only select and move 1 disk at a time 
    // 2) At any given location,  no larger disk should be at top of smaller disk 
    // 3 You can take help of the 3rd tower 

// In putput you just need to print the steps  

// https://leetcode.com/discuss/interview-question/1392284/solving-tower-of-hanoi-using-the-magic-of-recursion Beautiful explanation

// here tower b is destination, a is source and c is helper 

// Lets try writing an algorithm for shifting the disks from one tower to another using the third tower: (Please watch the gif at the top so as to understand the steps im listing)
// 1)Shift the first two disks from tower a to c using tower b
// 2)Shift the last disk from tower a to b
// 3)Now just put the first two disks back to tower b using tower a
// and we are done.

// Lets write a code for the above condition:

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
void toh(int n, char ta, char tb, char tc){
        //if we dont have any disks, then just end the function
        if(n == 0)
            return;

        /*
        now transfer n-1 (2 disks) from tower 1 to tower 3 using tower 2
         */
        toh(n-1, ta, tc, tb);

        //now transfer the third (nth) disk from tower a to b
        cout<<n<<" "<<"[ "<<ta<<" -> "<<tb<<"]"<<'\n';

        /*
        now just transfer those n-1 (2 disks) from tower c to tower b
         */
        toh(n-1, tc, tb, ta);
    }