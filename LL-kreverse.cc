/*Given a head to Linked List L, write a function to reverse the list taking k elements at a time.

You need not have to create a new list. Just reverse the old one using head.


Input Format:
The first line contains 2 space separated integers N and K

The next line contains N space separated integral elements of the list.

Constraints:
0 <= N <= 10^6
0 <= K <= 10^6
Output Format:
Display the linkedlist after reversing every k elements

Sample Input:
9 3
9 4 1 7 8 3 2 6 5
Sample Output:
1 4 9 3 8 7 5 6 2
Explanation:
N = 9 & K = 3, Original LL is : 9 -> 4 -> 1 -> 7 -> 8 -> 3 -> 2 -> 6 -> 5,
After k Reverse : 1 -> 4 -> 9 -> 3 -> 8 -> 7 -> 5 -> 6 -> 2
*/

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

void insertLL(node * & head , int n) {

	node * tail = NULL ;

	while (n--) {
		int x;
		cin >> x;
		node * n = new node (x);
		if (head == NULL)
		{
			head = n;
			tail = n;
		}
		else {
			tail->next = n;
			tail = tail->next;
		}

	}
}

node* reverseLL(node *head , int k) {

	node *c = head;
	node *n = NULL;
	node *prev = NULL;
	int count = 0;
	while (c != NULL && count < k ) {
		n = c->next;
		c->next = prev ;
		prev = c ;
		c = n;
		count++;
	}

	if (n != NULL) {
		head->next = reverseLL(n, k); /// MAIN STEP 
	}

	return prev; /// prev is the head of the new LL


}

int main () {

	int n;
	cin >> n;
	node * head = NULL;
	int K;
	cin >> K;
	insertLL(head, n);	
	head = reverseLL(head,K);
	print (head);
	return 0;
}