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

// We will first be learning disjoint set data struture
// Used in Kruskal Algorithm to detect a cycle ans also in a large no of competitive coding questions
// USeful in telling if two nodes belong to the same component or not (int the case graph has multiple components)

// It will provide us with 2 functions
// findParent()
// Union()

// Initially
// Assume no of nodes are 7 and intially assume that everyone forms a separate set/component
// So there are 7 unconnected components at start
// and everyone is itselfs parent also

//  (1) (2) (3) (4) (5) (6) (7)

// Union (1,2) means group them into one component
// Now updating parents. Pick any one as the parent
// So Parent of node 2 is 1
//  (1,2) (3) (4) (5) (6) (7)

// Union (2,3) means combine 2 and 3 into a single component
//  (1,2 ,3) (4) (5) (6) (7)
// Again set parent of node 3 as node 1

// Union (4,5)
//  (1,2,3) (4,5) (6) (7)
// make 4 as the parent

// Union (6,7)
//  (1,2,3) (4,5) (6,7)
// and make 6 as the parent

// Union 5,6
//  (1,2,3) (4,5,6,7)
// make 4 as the parent

// If someone asks, do 2 and 7 belong to same component?
// You will say no
// We can say no becoz both of them have different components

// Union (3,7)
//  (1,2,3 ,4,5,6,7)
// and make 1 as the parent


// Implementation
// efficient implementation is done by Union by Rank and Path compression

// so we have a parent array and initally every node is its own parent
// we will also have a rank array. This array will be intialed to 0

// so if we get union of (1,2)
// find their parents
// if different, then find their rank
// since intially rank is 0
// assign any node as parent of the other
// the node which is made parent
// its rank should increase by 1

// next we have union(2,3)
// so keep on finding parent till parent[i] == i
// then compare rank of the parent and this node
// who so evers rank is higher
// make the second node its child

// so here 1 will be the parent and has rank 1
// so we put 1 as the parent of 3

// when rank of two node are different, do nothing
// when they are same, increment any one and make it as the parent of the other node 


// rank is helpful as it helps in reducing the size of the treee
// if we go by rank algo
// tree is  
//          1
//         / \ 
//        2   3

// if we didnt follow rank and made anyone the parent
// tree could look like 

//          3
//           \ 
//            1 
//              \ 
//                2

// So this is called UNION BY RANK

// Path compression is ki if 4 is parent of 6 and 6 is parent of 7
// so ultimately 4 will be parent of 7
// so we directly connect 7 to 4

// Can be easily achieved by updating the parent array
// Time complexity is O(1) for each Union step
// so for m such steps it is O(M)

int* parent = new int[100000];
int* rankArray = new int[100000];

void makeSet()
{
    for(int i = 0; i < 100000; i++){
        parent[i] = i;
        rankArray[i] = 0;
    }
}

int findParent(int node){

    // base case
    // if node is the parent of itself
    if(node == parent[node]){
        return node;
    }

    // if this is not the case
    // keep on looking

    // this also achieves path compression
    // as we assign the final parent to all these nodes
    return parent[node] =  findParent(parent[node]);

}

void unionSet(int u, int v){

    u = findParent(u);
    v = findParent(v);

    if(rankArray[u] < rankArray[v]){
        parent[u] = v;
    }
    else if(rankArray[v] < rankArray[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rankArray[u]++;
    }

}


int main(){
    
    // basically intializes the disjoint set
    makeSet();
    return 0;

}