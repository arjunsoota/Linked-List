/*Palindrome
Check if a linked list is a palindrome.( Boolean return type )

Input Format:
Add N space separated elements in the list
Constraints:
None
Output Format:
Boolean answer( true or false)

Sample Input:
5
1 2 3 6 8
Sample Output:
False
*/

#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* next;
	node(int d) {
		data = d;
		next = NULL;
	}
};

node* insertLL(node* head, int n) {
	node* tail = NULL;
	while (n--) {
		int x;
		cin >> x;
		node* n = new node(x);
		if (head == NULL)
		{
			head = n;
			tail = n;
		}
		tail->next = n;
		tail = tail->next;
	}
	return head;
}

void print(const node* head) {

	while (head) {
		cout << head->data << " " ;
		head = head->next;
	}
}

// reverse the list

void reverse( node*& head) {

	node* cur = head;
	node* temp;
	node* prev = NULL;
	while (cur)
	{	temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}
	head = prev;

}

node* copylist(const node* head)
{
	node* nhead = NULL;
	node* ntail = NULL;
	while (head) {
		node* n = new node(head->data);
		if (nhead == NULL)
		{
			nhead = n;
			ntail = n;
		}
		ntail->next = n;
		ntail = ntail->next;
		head = head->next;
	}
	return nhead;
}

bool compare(node* head , node*nhead) {

	while (head && nhead) {
		if (head->data != nhead->data)
			return false;
		head = head->next;
		nhead = nhead->next;
	}
	return true;

}

int main()
{
	node* head = NULL;
	int n;
	cin >> n;
	head =  insertLL(head, n);
	//print(head);
	node* nhead = copylist(head);
	//cout<<endl;
	//print(nhead);
	//cout<<endl;
	reverse(head);
	bool ans = compare(head, nhead);
	if (ans)
		cout << "true";
	else
		cout << "false";
	//print(head);


	return 0;
}