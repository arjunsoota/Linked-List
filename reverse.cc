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


void reverse(node * &head) {
	//ITERATIVE

	node * c = head;
	node*prev = NULL;
	node * n;
	while (c != NULL) {

		n = c->next;
		c->next = prev;
		prev = c;
		c = n;
	}

	head = prev;

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
	int t=1;
	while (t--)
	{

		int n1, n2;
		cin >> n1;
		node * head1 = insertLL( n1);
		reverse(head1);
		print(head1);
		//print(head2);

	}
	return 0;
}