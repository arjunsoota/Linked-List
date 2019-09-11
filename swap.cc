#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data ;
	node * next ;
	node(int d) {
		data = d;
		next = NULL;
	}
};
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
			tail = tail->next;
		}


	}
}

void print(node * head) {

	node * temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void myswap(node * head , int x , int y )
{

	node * temp1 = NULL;
	node * temp2 = NULL;
	if (x == y)
		return;
	while (head != NULL) {
		if (head->data == x)
			temp1 = head;
		if (head-> data == y)
			temp2 = head;
		head = head->next;
	}
	if (temp1 == temp2)
		return;


	int temp = temp1->data;
	temp1->data = temp2->data;
	temp2->data = temp;

}
int main()
{
	node * head = NULL;
	int n;
	cin >> n;
	insertLL(head, n);
	int n1, n2;
	cin >> n1 >> n2;
	myswap(head, n1, n2);
	print(head);


	return 0;
}