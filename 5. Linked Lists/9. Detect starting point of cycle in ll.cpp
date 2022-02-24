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


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        if(!head){
            return NULL;
        }
        
        if(head->next == head){
            return head;
        }
        
        slow = head->next;
        if(head->next){
            fast = head->next->next;
        }
        else{
            return NULL;    
        }
        
        while(fast != NULL && fast->next != NULL)
        {
            if(slow != NULL)
            {
                slow = slow->next;
            }
            
            if(fast->next != NULL)
            {
                fast = fast->next->next;
            }
            
            if(fast == slow)
            {
                break;
            }
        }
        
        if(fast == NULL || fast->next == NULL){
            return NULL;
        }
        
        slow = head;
        
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;

        
    }
};