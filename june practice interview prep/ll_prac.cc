#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *next;
	node(int d) {
		data = d;
		next = NULL;
	}
};
// here passing by value because we dont want the value of head in main to change
void printLL(node *head) {

	node *temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << endl;
}
int length(node *head) {
	node *temp = head;
	int len = 0;
	while (temp != NULL) {
		temp = temp->next;
		len++;
	}
	return len;
}
//INSERTION
// passing by reference because we want to update the value of head pointer
void insertatHead(node *&head, int data) {

	// dynamic memory allocation
	node * n = new node(data);
	n->next = head;
	head = n;
}
void insertAtTail(node *&head , int data) {

	if (head == NULL)
	{
		insertatHead(head, data);
		return;
	}
	node *tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next  = new node(data);
	return;
}
void insertAtMiddle(node *&head , int data, int p) {

	if (head == NULL || p == 0) {
		//insert at head
		insertatHead(head, data);
	}

	else if ( p > length(head)) {
		//insert at tail
		insertAtTail(head, data);

	}
	else {
		//insert at middle
		int jump = 1;
		node *temp = head;
		while (jump <= p - 1) { // reach the middle
			temp = temp->next;
			jump++;
		}
		node *n = new node(data);
		n->next = temp->next;
		temp->next = n;
	}
}
//DELETION
void deleteAtHead(node *& head) {
	if (head == NULL) return;
	node *temp = head;
	head = head->next;
	delete temp;
	return;
}
void deleteAtTail(node*&head) {
	node *prev = NULL;
	node *temp = head;
	while (temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}
	delete temp;
	prev->next = NULL;
	return;
}
void deleteAtMiddle(node *&head, int p) {
	if (head == NULL || p == 0)
		deleteAtHead(head);
	else if (p > length(head)) {
		deleteAtTail(head);
	}
	else {
		//now delete at middle
		int jump = 1;
		node *prev = NULL;
		node *temp = head;
		while (jump <= p - 1) {
			jump++;
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		delete temp;
		return;
	}
}

void buildList(node *&head) {
	int data;
	cin >> data;
	while (data != -1) {
		insertAtTail(head, data);
		cin >> data;
	}///
}
//SEARCH FUNCTIONS
bool searchRecursive(node *head, int key) {
	if (head == NULL)
		return false;
	if (head->data == key)
		return true;
	else
		return searchRecursive(head->next, key);
}
bool searchIterative(node *head, int key) {

	node*temp = head;
	while (temp != NULL) {
		if (temp->data == key)
			return true;
		temp = temp->next;
	}
	return false;
}
//REVERSING A LINKED LIST
void RreverseIterative(node*&head) {
	node *c = head;
	node *p = NULL;
	node *n;
	while (c != NULL) {
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	head = p;
}
node* ReverseRecursive(node*&head) {
	// base case
	if (head == NULL || head->next == NULL)
		return head;
	//recursive case
	node *smalHead = ReverseRecursive(head->next);
	node *c = head;
	c->next->next = c;
	c->next = NULL;
	return smalHead;
}
//mid-point of linked list RUNNER TECHNIQUE
node* midpoint(node*head) {
	if (head == NULL || head->next == NULL)
		return head;
	node *slow = head;
	node *fast = head->next;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//Kth node from end
node* knode(node *head, int k) {
	if (head == NULL || head->next == NULL)
		return head;
	node* slow = head;
	node * fast = head;
	while (k > 0 && fast != NULL)
	{
		fast = fast->next;
		k--;
	}
	while (fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

//merge two sorted LL
node * merge(node *a, node* b) {
	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;
	node *c = NULL;
	if (a->data < b->data) {
		c = a;
		c->next = merge(a->next, b);
	}
	else {
		c = b;
		c->next = merge(a, b->next);
	}
	return c;
}

// merge sort on LL
node* mergesort1(node *head) {
	//base case
	if (head == NULL || head->next == NULL)
		return head;
	//divide -- break at mid
	node*mid = midpoint(head);
	node *a = head;
	node *b = mid->next;
	mid->next = NULL;
	//recursively sort
	a = mergesort1(a);
	b = mergesort1(b);
	//conquer

	node *c = merge(a, b);

	return c;
}

int main()
{
	node *head = NULL;
	node *head2 = NULL;
	buildList(head);
	// buildList(head2);
	printLL(head) ;

	// node *mid = midpoint(head);
	// cout << mid->data;

	// head = mergesort1(head);

	// printLL(head) ;
	// node*mid = knode(head,3);
	// cout << mid->data;
	// cout << endl;
	// cout << searchRecursive(head, 10) << endl;
	// cout << searchIterative(head, 20) << endl;
	// head = ReverseRecursive(head);
	// printLL(head) ;

	return 0;
}