// 1) calculate middle of ll (howvere here we will stop at 2nd last node(for even) or last node(for odd))
// 2) slow->next will point to second half of list
// 3) Reverse ll from slow->next and also assign new head to slow->next
// 4) make slow = slow->next
// 5) while(slow != null) {check head->val == slow->val}
// if all checks return true 

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

// take an example to see why this code works
class Solution {
    bool isPalindrome(ListNode* head) {

        if(head==NULL||head->next==NULL)
            return true;
        
        // fast and slow pointers to find middle of LL
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        // reversing second half and assigning it to next of slow
        slow->next=reverseList(slow->next);
        // moving slow by one
        slow=slow->next;

        // then checking one by one
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
        
            head=head->next;
            slow=slow->next;
        }

        return true;
    }

    // function to reverse LL
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};