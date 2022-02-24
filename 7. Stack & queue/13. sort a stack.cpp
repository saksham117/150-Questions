#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<map>

using namespace std;

// Algorithm 
// We can use below algorithm to sort stack elements: 



// sortStack(stack S)
//     if stack is not empty:
//         temp = pop(S);  
//         sortStack(S); 
//         sortedInsert(S, temp);
// Below algorithm is to insert element is sorted order: 

// sortedInsert(Stack S, element)
//     if stack is empty OR element > top element
//         push(S, elem)
//     else
//         temp = pop(S)
//         sortedInsert(S, element)
//         push(S, temp)

// C++ program to sort a stack using recursion

// Stack is represented using linked list
struct stack {
	int data;
	struct stack* next;
};

// Utility function to initialize stack
void initStack(struct stack** s) { *s = NULL; }

// Utility function to check if stack is empty
int isEmpty(struct stack* s)
{
	if (s == NULL)
		return 1;
	return 0;
}

// Utility function to push an item to stack
void push(struct stack** s, int x)
{
	struct stack* p = (struct stack*)malloc(sizeof(*p));

	if (p == NULL) {
		fprintf(stderr, "Memory allocation failed.\n");
		return;
	}

	p->data = x;
	p->next = *s;
	*s = p;
}

// Utility function to remove an item from stack
int pop(struct stack** s)
{
	int x;
	struct stack* temp;

	x = (*s)->data;
	temp = *s;
	(*s) = (*s)->next;
	free(temp);

	return x;
}

// Function to find top item
int top(struct stack* s) { return (s->data); }


// ######################## MAIN FUNCTION OF CONCERN ####################################  
// Recursive function to insert an item x in sorted way
void sortedInsert(struct stack** s, int x)
{
	// Base case: Either stack is empty or newly inserted
	// item is greater than top (more than all existing)
	if (isEmpty(*s) || x > top(*s)) {
		push(s, x);
		return;
	}

	// If top is greater, remove the top item and recur
	int temp = pop(s);
	sortedInsert(s, x);

	// Put back the top item removed earlier
	push(s, temp);
}

// Function to sort stack
void sortStack(struct stack** s)
{
	// If stack is not empty
	if (!isEmpty(*s)) {
		// Remove the top item
		int x = pop(s);

		// Sort remaining stack
		sortStack(s);

		// Push the top item back in sorted stack
		sortedInsert(s, x);
	}
}


