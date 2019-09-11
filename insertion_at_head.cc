#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data ;
	node * next;
	node(int d) {
		data = d;
		next = NULL;
	}
};

void insertathead(int data, node*&head) {

	node*n = new node (data);
	n->next = head;
	head = n;
}
void insertattail(int data, node*&head) {

	if (head == NULL)
	{
		insertathead(data, head);
		return;
	}
	node *tail = head;
	while (tail-> next != NULL) {
		tail = tail->next;
	}

	tail->next = new node(data);
	return;
}

int length(node * head) {

	int len = 0;
	node * temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
		len++;
	}
	return len;
}

void insertmiddle(int data , node*&head , int p) {


	if (head == NULL || p == 0) {
		insertathead(data, head);
	}
	else if (p > length(head)) {
		insertattail(data, head);
	}
	else {
		//insert in middle
		//reach the pos

		int jump = 1;
		node *temp = head;
		while (jump <= p - 1)
		{
			temp = temp->next;
			jump++;
		}
		node *n = new node(data);
		n->next = temp->next;
		temp->next = n;
	}
}

void deleteatHead(node*&head) {

	if (head == NULL)
		return;
	node * temp = head;
	head = head->next;
	delete temp;
	return;
}

void deleteatTail(node*&head) {

	node * prev = NULL;
	node* temp = head;
	while (temp->next != NULL) {

		prev = temp;
		temp = temp->next;
	}
	delete temp;
	prev->next = NULL;
	return;
}

void deleteatMiddle(node*&head, int p) {

	if (head == NULL || p == 0)
	{
		deleteatHead(head);
		return;
	}
	else if (p > length(head)) {
		deleteatTail(head);
		return;
	}
	else {

		int jump = 1;
		node * prev = NULL;
		node * temp = head;
		while (jump <= p ) {
			prev = temp;
			temp = temp->next;
			jump++;

		}

		prev->next = temp->next;
		delete temp;
		return;
	}
}

void print(node * head) {

	node * temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << endl;
}


node* midpoint(node * head) { // RUNNER TECHNIQUE

	if (head == NULL || head->next == NULL)
		return head;

	node * slow = head;
	node * fast = head -> next;
	while (fast != NULL && fast->next != NULL) {

		fast = fast->next->next;
		slow = slow->next;

	}

	return slow ;

}

node * kNODE(node * head, int k ) {
	if (head == NULL || head->next == NULL)
		return head;
	node * slow = head;
	node * fast = head;
	while (k > 0 && fast != NULL) {
		fast = fast->next;
		k -= 1;
	}
	//cout<<fast->data<<endl;
	while (fast != NULL) {
		slow = slow->next;
		fast = fast->next;
	}

	return slow;

}

void insert(node *&head) {

	int data;
	cin >> data;
	while (data != -1) {
		insertattail(data, head);
		cin >> data;
	}


}

node *  merge(node * a , node * b) {

	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;
	node * c;
	if (a->data < b->data) {
		c = a;
		c->next = merge(a->next, b);
	}
	else {
		c = b;
		c->next = merge (a, b->next);
	}
	return c;
}

node * mergesort(node * &head) {


	//base case
	if (head == NULL || head->next == NULL)
		return head;
	//rec case
	//1. midpoint
	node * mid = midpoint(head);
	node * a = head;
	node * b = mid->next;
	mid->next = NULL;

	//2. recursively call mergesort to DIVIDE

	a = mergesort(a);
	b = mergesort(b);

	//3.CONQUER

	node * c = merge(a, b);

	return c;



}

node * reverse1(node *& head) { // RECURSIVE


	// base case
	if (head == NULL || head -> next == NULL) {
		return head ;
	}

	// rec case
	node * smallhead = reverse1(head->next);
	node * c = head;
	c->next->next = c;
	c->next = NULL;
	return smallhead;
}

void reverse(node *& head) { //ITERATIVE

	node * cur = head;
	node * prev = NULL;
	node * n;

	while (cur != NULL) {

		n = cur->next;
		cur->next = prev;
		prev = cur;
		cur = n;

	}

	head = prev;


}
int main()
{

	node * head = NULL;
	node * head1 = NULL;
	//inserting own elements in a linked list

	insert(head);
	//insert(head1);

	//head = merge(head, head1);

	//head = mergesort(head);
	//head = reverse1(head);
	/*node N(6);
	head = &N; //adding node using object
	print(head);
	insertathead(5, head);
	print(head);
	insertathead(4, head);
	print(head);
	insertathead(3, head);
	print(head);
	insertattail(7, head);
	print(head);
	insertmiddle(8, head, 3);
	print(head);
	insertmiddle(10, head, 3);
	print(head);
	deleteatHead(head);
	print(head);
	deleteatTail(head);
	print(head);
	deleteatMiddle(head,2);
	print(head);

	node * m = midpoint(head);
	cout << m->data << endl;
	node * k = kNODE(head, 3);
	cout << k->data << endl;*/
	print(head);
	node * k = kNODE(head, 3);
	cout << k->data << endl;

	return 0;
}