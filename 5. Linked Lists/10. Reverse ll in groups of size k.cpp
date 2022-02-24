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
    int length(ListNode *head){
        int size = 0;
        while(head != NULL){
            size+=1;
            head= head->next;
        }

        return size;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL || k == 1){
            return head;
        }

        int size = length(head);

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head;
        
        ListNode* tail = head;
        ListNode* nextTail = head;
        ListNode* newHead = NULL;

        while(size >= k){

            for(int i = 0; i < k; i++){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            if(newHead == NULL){
                newHead = prev;
            }
            else{
                tail->next = prev;
                tail = nextTail;
            }

            prev = NULL;
            nextTail = curr;
            size -= k;
        }

        if(size){
            tail->next = nextTail;
        }

        return newHead;

    }
};