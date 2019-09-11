#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node * next; // self referential class

	node(int d) {
		data = d;
		next = NULL;
	}
};


node *  createLL() {

	int x;

	node * head = NULL;
	node * tail = NULL;
	while (true) {
		cin >> x;
		if (x == -1) break;

		node * newnode = new node (x);
		if (head == NULL) {
			head = newnode;
			tail = newnode;
		}
		else {
			tail->next = newnode;
			tail = tail->next;
		}



	}
	return head;

}
void printLL(const node * head) {

	while (head != NULL)
	{
		cout << head->data << "->";
		head = head->next;
	}

}


void floydCycle(node * head) {

	node * tortoise = head;
	node * hare = head;
	node * temp = head;
	while (temp && hare && hare->next) {

		hare = hare->next->next;
		tortoise = tortoise->next;
		if (hare == tortoise)
			break;
		temp=temp->next;
	}

	tortoise = head;
	while (tortoise != hare) {
		hare = hare -> next;
		tortoise = tortoise->next;
	}

	cout<<hare->data<<" is the starting of the cycle \n";

	// now they are at the begginging of the cycle 

	//this will remove the cycle
	while (tortoise->next != hare)
		tortoise = tortoise->next;
	tortoise->next = NULL;
	return; 

}


int main()
{

	node * head = NULL;
	head = createLL();
	head->next->next->next->next->next = head->next->next;
	floydCycle(head);
	printLL(head);
	return 0;
}