#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data ;
	node * next ;
	node ( int d ) {
		data = d ;
		next = NULL;
	}
};

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

node *  insertLL(int n ) {


	node * head = NULL;
	node * tail = NULL;
	while (n--) {

		int x;
		cin >> x;
		node * n = new node (x);
		if (head == NULL) {
			head = n;
			tail = n;
		}

		else {
			tail->next = n;
			tail = tail->next;
		}


	}
	return head ;
}

void print(node * head) {

	node * temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int n1, n2;
		cin >> n1;
		node * head1 = insertLL( n1);
		cin >> n2;
		node * head2 = insertLL( n2);
		head1=merge(head1,head2);
		print(head1);
		//print(head2);

	}
	return 0;
}