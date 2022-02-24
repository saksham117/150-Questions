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

// n^2 solution is to traverse each row, and if in that row, none of that column is 1 and also every other row has a 1 correspondin to this row
// then that is a celebrity

// Also. we cannot have 2 celebrites, because for even on celebirty to exist, one complete row has to be filled with zeros 
// nut now since this celebirty knows about another celebirty, then there should be a 1 at some index
// since this is not possible and it violates the conditions for a single celebrity, therfore we say ki if a celebrity exists
// then there is only going to be one celebrity

// It is also totally possible that there are zero celebrities

// we will use an approach, which we used to use in class 11th, the Elimination Approach
// One by one we will eliminate all the possible options 

// Matrix

// 0 1 1 1
// 1 0 1 0
// 0 0 0 0
// 1 1 1 0

// Algo
// 1) if I have a 4X4 matrix, so indices will be 0,1,2,3
//   So push 0,1,2,3 to stack 

//  2) Pop two eleemnts at once, say 2,3 
//  We will se ki whether 2 knows 3 
// a) If 2 does not know 3, then 3 cannot be a celebrity so elimnate 3
// b) if 2 does know 3 and 3 does not know 2, then 3 is a possible solution and we elimante 2


// Lets say 2-a is true. So we push 2 back to stack 
// Now pop 2 and 1
// here check if one knows 2 or not. In our example it is yes, so one cannot be the solutuin
// so just push back 2

// now we have 0 and 2 
// check if 0 knows 2 
// ans is yes, So 0 cannot be celbirty

// and now we are just left with a single element that is 2 
// so for this row, just iterate completely and if all indices are zero, and for that column excpet matorx[2][2], if everything is 1
// then 2 is indeed a celebrity, falls otherwise 

// Just fix in what order you want to compare
// if first is element 1 popped and second is element 2 popped
// then we check for matrix[first][second]


class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here
        stack<int> s; 
        for(int i = 0; i < n; i++){
            s.push(i);
        }

        while(s.size() > 1){
            
            int first = s.top();
            s.pop();
            int second = s.top();
            s.pop();

            // means first knows second, then first cannot be celebirty
            if(M[first][second] == 1){
                s.push(second);
            // means first does not know second, then second cannot be celbirty
            }else{
                s.push(first);
            }
        }

            // retrieve the single element remaining in the stack
            int element = s.top();
            s.pop();

            // check if row corresponding to element has all zeros
            for(int j = 0; j < n; j++){
                if(M[element][j] != 0){
                    return -1;
                }
            }

            // check if column correpsonding to element has all 1s excelt when i == element itself
            for(int i = 0; i < n; i++){
                if(i != element){
                    if(M[i][element] != 1){
                        return -1;
                    }
                }
            }

            // Above for loops can be condensed into a single one
            // for(int i = 0; i < n; i++){
            //     if(i != element){
            //         if(M[i][element] == 0 || M[element][i] == 1 ){
            //             return -1;
            //         }
            //     }
            // }

            return element;
        
    }
};
