#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data ;
	node * next;
	node(int d) {
		data = d ;
		next = NULL;

	}
};

void insertLL(node *& head , int n ) {
	node * tail = NULL;
	while (n--) {

		int x;
		cin >> x;
		node * n = new node (x);

		if (head == NULL)
		{
			head = n;
			tail = n;

		}

		else
		{
			tail->next = n;
			tail = tail->next;
		}

	}

}

void print(node * head) {

	while (head) {
		cout << head->data << "->";
		head = head->next;
	}
	cout << endl;

}


void duplicate(node * head){

	node * temp = head->next;
	node * prev = head;
	node * c = NULL;
	if(head==NULL || head->next==NULL)
		return ;

	while(temp){

			if(temp->data == prev->data){

					c=temp;
					prev->next = temp->next;
					temp=temp->next;
					delete c;

			}
			else{
				
				prev=temp;
				temp=temp->next;

			}


	}

}
int main()
{

	int n;
	cin >> n;
	node * head = NULL;
	insertLL(head, n);
	duplicate(head);
	print(head);
	return 0;
}