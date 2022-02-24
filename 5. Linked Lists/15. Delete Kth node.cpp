//Link list Node 
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

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

Node* deleteK(Node *head,int k)
{
  //Your code here
//   return head
    if(k == 0){
        return head;
    }
    
    if(k == 1){
        return NULL;
    }
    
        
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr != NULL && curr->next != NULL){
        
        for(int i = 1; i < k; i++){
            if(curr == NULL){
            return head;
        }
            prev = curr;
            curr = curr->next;
        }
        if(curr == NULL){
            return head;
        }
        prev->next = curr->next;
        curr->next = NULL;
        curr = prev->next;
    }
    
    return head;
}
