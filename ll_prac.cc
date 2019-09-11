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

node * Delete (node * & head , int datatodelete){

	node * prev = NULL;
	node * temp = head;

	while(temp!=NULL){
	if(temp->data==datatodelete)
		{
			if(prev==NULL)
				// means we are deleting head 
			{
				head = temp->next;
				delete temp;
			}
		else
		{	
			prev->next=temp->next;
			delete temp;
		}
		break;
	}
	else
	{
		prev = temp;
		temp=temp->next;
	}
}
 return head ;  

}

void reverselist ( node * & head ){

	node * temp = head->next ; 
	node * prev = NULL;
	node * c =head;
	while (temp!=NULL){
		
		c->next=prev;
		prev=c;
		c=temp;
		temp=temp->next;
	}
	head=temp;

}

void printLL(const node * head) {

	while (head != NULL)
	{
		cout << head->data << "->";
		head = head->next;
	}

}

int main()
{
	node * head = NULL;
	head = createLL();
	reverselist(head);
	/*int data;
	cin>>data;
	head = Delete(head,data);
*/	printLL(head);

	return 0;
}