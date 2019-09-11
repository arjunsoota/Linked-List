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
void print(node * head) {

	node * temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << endl;
}
node * kNODE(node * head, int k ,int n ) {
	if(k>=n) k=k%n;
	if(k==0) return head;

	if (head == NULL || head->next == NULL)
		return head;
	node * slow = head;
	node * fast = head;
	node * prevS = NULL;
	node * prevF = NULL;
	while (k > 0 && fast != NULL) {
		prevF = fast;
		fast = fast->next;
		k -= 1;
	}
	//cout<<fast->data<<endl;
	while (fast != NULL) {
		prevS = slow;
		prevF=fast;
		slow = slow->next;
		fast = fast->next;
	}

	prevS->next= NULL;
	prevF->next=head;
	return slow;

}

void insertLL(node * & head , int n){

	node * tail = NULL ;

	while(n--){
		int x;
		cin>>x;
		node * n = new node (x);
		if(head==NULL)
		{
			head =n;
			tail=n;
		}
		else {
			tail->next= n;
			tail=tail->next;
		}

	}
}


int main (){

	int n;
	cin>>n;
	node * head = NULL;
	insertLL(head,n);
	int K;
	cin>>K;
	head =kNODE(head,K,n);
	//cout<<k->data<<endl;
	print (head);


	return 0;
}