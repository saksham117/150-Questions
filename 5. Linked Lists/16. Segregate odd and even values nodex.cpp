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

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(head == NULL){
            return head;    
        }
        
        Node* evenHead = NULL;
        Node* oddHead = NULL;
        Node* evenCurr = NULL;
        Node* oddCurr = NULL;
        
        while(head != NULL){
            // cout<<head->data<<'\n';
            if(head->data % 2 == 0){
                if(!evenHead){
                    evenHead = head;
                    evenCurr = evenHead;
                }
                else{
                    evenCurr->next = head;
                    evenCurr = evenCurr->next;
                }
                
            }
            else{
                if(!oddHead){
                    oddHead = head;
                    oddCurr = oddHead;
                }
                else{
                    oddCurr->next = head;
                    oddCurr = oddCurr->next;
                }
                
            }
            
            head = head->next;
        }
        
        if(oddHead){
            oddCurr->next = NULL;
        }
        
        if(!evenHead){
            return oddHead;
        }
        
        evenCurr->next = oddHead;
        return evenHead;
        
        
    }
};