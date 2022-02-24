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

//Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};



// Just use the concept of merging 2 sorted ll
// on each of these n nodes 
// it is that simple
Node* mergeTwoLists(Node* l1, Node* l2) {

    if(l1 == NULL)
    {
        return l2;
    }


    if(l2 == NULL)
    {
        return l1;
    }

    Node* head = NULL;
    Node* tail = NULL;

    while(l1 != NULL && l2 != NULL)
    {
        if(l1->data <= l2->data)
        {
            if(head == NULL)
            {
                head = l1;
                tail = l1;
            }
            else
            {
                tail->bottom = l1;
                tail = tail->bottom;
                
            }
            
            l1 = l1->bottom;
        }
        else
        {
            if(head == NULL)
            {
                head = l2;
                tail = l2;
            }
            else
            {
                tail->bottom = l2;
                tail = tail->bottom;
                
            }
            
            l2 = l2->bottom;
        }
    }

    while(l1 != NULL)
    {
        tail->bottom = l1;
        tail = tail->bottom;
        l1 = l1->bottom;
    }

    while(l2 != NULL)
    {
        tail->bottom = l2;
        tail = tail->bottom;
        l2 = l2->bottom;
    }

    return head;

}


// did it iteratively
// it works
// no need to follow striver method where he says to do recursion


/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   
   if(!root){
       return root;
   }

   Node* finalHead = root;

   while(finalHead->next != NULL){
        Node* h1 = finalHead;
        Node* h2 = finalHead->next;
        Node* nextNode = finalHead->next->next;
        h1->next = NULL;
        h2->next = NULL;
        finalHead = mergeTwoLists(h1,h2);
        finalHead->next = nextNode;
   }

   return finalHead;

}