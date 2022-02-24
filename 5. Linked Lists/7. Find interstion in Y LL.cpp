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

// Normal approach is to use HashMap and store all nodes of LL1 and then check if any of the same nodes is present in LL2
// or not. So easy approach but requires extra space

// This next approach is super cool
// Calculate length of both ll
// Whichever is greater, move head of that ll by amount equal to diff in len of the two ll
// Then iterate on both ll, one node after the other
// As soon as they match, return

// So good good approach

class Solution {
public:
    int length(ListNode* head)
    {
        int length = 0;
        while(head != NULL)
        {
            length+=1;
            head = head->next;
        }

        return length;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *dummyA = headA;
        ListNode *dummyB = headB;

        int a = length(dummyA);
        int b = length(dummyB);
        int diff = 0;

        dummyA = headA;
        dummyB = headB;


        if(a > b)
        {
            diff = a-b;

            for(int i = 0; i < diff; i++)
            {
                dummyA = dummyA->next;
            }
        }
        else{
            diff = b-a;
            for(int i = 0; i < diff; i++)
            {
                dummyB = dummyB->next;
            }
        }


        while(dummyA != NULL && dummyB != NULL)
        {
            if(dummyA == dummyB)
            {
                return dummyA;
            }
            else
            {
                dummyA = dummyA->next;
                dummyB = dummyB->next;
            }
        }


        return NULL;
    }
};

// Another approach having same complexity would be
// Move head of both one by one
// if head of ll1 becomes null, move it to start of ll2
// then move both by 1
// when head of ll2 becomes null, move it to start of ll1
// now both of them would be at same distance from interstion point. Basically in this time head of ll1 would have
// covered the extra length of ll2. So thats why both would be at same distance
// then move both of them one by one
// as soon as they match, return that node!!

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
    
        ListNode *a = headA;
        ListNode *b = headB;

        //if a & b have different len, then we will stop the loop after second iteration
        while( a != b){
            //for the end of first iteration, we just reset the pointer to the head of another linkedlist
            a = a == NULL? headB : a->next;
            b = b == NULL? headA : b->next;    
        }

        return a;

    }
};
