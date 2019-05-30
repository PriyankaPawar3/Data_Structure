// this file will contain all code for stacks
#include<iostream>
#include<malloc.h>
using namespace std;
struct Node{
	int data;
	struct Node* next;
};

void insertNodeAtHead(struct Node**);

struct Node* createLinkedList(int size){
	struct Node* head = NULL;
	while(size){
		insertNodeAtHead(&head);
		size--;
	}
	return head;
}
void insertNodeAtHead(struct Node** head){
	cout<<"Enter node data: ";
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	cin>>new_node->data;
	new_node->next = *head;
	*head = new_node;

}
void traverse(struct Node* head){
	cout<<"Traversing Linked list...."<<endl;
	struct Node* temp=head;
	while(temp){
		cout<<"Node - "<<temp->data<<endl;
		temp=temp->next;
	}
}
int main()
{
	cout<<"Enter size of linked list: ";
	int size = 0;
	cin>>size;
	struct Node* head = createLinkedList(size);
	traverse(head);

	return 1;
}

