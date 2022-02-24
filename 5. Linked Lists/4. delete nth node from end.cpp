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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // creating a duumy node called start
        ListNode * start = new ListNode();
        start -> next = head;
        // making fast and slowpoint to the dummy node
        ListNode* fast = start;
        ListNode* slow = start;     

        // moving fast pointer initially n times
        for(int i = 1; i <= n; ++i)
            fast = fast->next;

        // then moving fast and slow one by one till fast becomes last node
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        // just change the links of the slow pointer
        slow->next = slow->next->next;
        
        // alwasy return start->next
        return start->next;
    }
};


// my old approach
class Solution {
public:
    
    int length(ListNode* head)
    {
        int count = 0;
        while(head != NULL)
        {
            count += 1;
            head = head->next;
        }
        
        return count;
    }
    
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == NULL)
        {
            return NULL;
        }
        
        int l = length(head);
        
        if(n == l)
        {
            ListNode* temp = head->next;
            head->next = NULL;
            delete head;
            return temp;
        }
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        for(int i = 0; i < l - n; i++)
        {
            prev = curr;
            curr = curr->next;
            
        }
        
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        
        return head;
        
        
        
    }
};