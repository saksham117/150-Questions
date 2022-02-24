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

// easy question
// only additonal point in this is ki k, ie number of times that we can rotate can be greater than n. ie size of ll
// so we can say k = k%N, because of rotation property

// now rest is very easy and code is self explanatory
// below code is 1 year old
// logic is this only but I can certainly optimize it!!

class Solution {
public:
    
    int length(ListNode* head)
    {   
        int l = 0;
        
        while(head != NULL)
        {
            l += 1;
            head = head->next;
        }
        
        return l;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL)
        {
            return NULL;
        }
        
        if(head->next == NULL)
        {
            return head;
        }
        
        int l = length(head);
        
        k = k%l;
        
        if(k == 0)
        {
            return head;
        }
        
        
        
        ListNode *new_head = NULL;
        ListNode *tail = NULL;
        
        ListNode *temp = head;
        int count = 0;
        
        while(count < (l-k-1))
        {
            temp = temp->next;
            count++;
        }
        
        new_head = temp->next;
        temp->next = NULL;
        
        temp = new_head;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        
        tail = temp;
        
        tail->next = head;
        
        return new_head;

        
    }
};