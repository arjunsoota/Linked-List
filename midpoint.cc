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

void insertLL(node *& head , int n ) {

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
			tail = n;
		}


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

int main()
{
	node * head = NULL;
	int n;
	cin >> n;
	insertLL(head, n);
	print(head);
	node * mid = midpoint(head);
	cout << mid->data;

	return 0;
}