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

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Looks tough but is easy
// just maintain an unordered_mapof type Node*, Node*
// where key will be Node* of original ll and value will be Node* of our new ll
// will require two pass
// in first pass, create new nodes, assign their next and for random, make them point to random of original ll only

//  a1 a2 a3 a4
// b1 b2 b3 b4
//  a nd b are addresses

// map = 
// a1: b1
// a2: b2
// a3: b3
// a4: b4


// if a1 ka random is a3

// so in second pass, when we land on b1
// we will have b1 random also as a3
// so we will update it
// b1 -> random = map[b1->random];
// so now b1->random will be b3
// that is whats required