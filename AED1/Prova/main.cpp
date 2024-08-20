// C++ program to delete all occurrences
// of a given key in linked list
#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node
{
	public:
		int data;
		Node* next;
};

// Given a reference (pointer) to the head
// of a list and an int, inserts a new node
// on the front of the list
Node* push(Node* head, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;
	return head;
}

// Given a reference (pointer)to the head
// of a list and a key, deletes all
// occurrence of the given key in
// linked list
void deleteKey(Node *head,int x)
{
	if (head->data == x)
		head->next = head;
	// Store head node
	Node *tmp = head;
	
	while (head->data == x)
	{
		head = head->next;
	}
	while (tmp->next != NULL)
	{
		if (tmp->next->data == x)
		{
			tmp->next = tmp->next->next;
		}
		else
		{
			tmp = tmp->next;
		}
	}
	return;
}

// This function prints contents of
// linked list starting from the
// given node
void printList(Node* node)
{
	while (node->next != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << node->data;
}

// Driver code
int main()
{
	
	// Start with the empty list
	Node* head = NULL;
	head = push(head, 7);
	head = push(head, 2);
	head = push(head, 3);
	head = push(head, 2);
	head = push(head, 8);
	head = push(head, 1);
	head = push(head, 2);
	head = push(head, 2);
	
	// Key to delete
	int key = 2 ;

	cout << "Created Linked List:\n ";
	printList(head);

	// Function call
	deleteKey(head, key);
	cout << "\nLinked List after Deletion is:\n";
	
	printList(head);
	
	return 0;
}

// This code is contributed by shivamsharma2020

