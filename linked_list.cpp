// this file will contain all code for stacks
#include<iostream>
#include<malloc.h>
using namespace std;
struct Node{
	int data;
	struct Node* next;
};

void insertNodeAtHead(struct Node**);

struct Node* createLinkedList(){
	cout<<"Enter the size of linked list: ";
	int size = 0;
	cin>>size;
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
void insertAt(struct Node** head, int pos, int value){
	struct Node* temp = *head;
	int c=1;
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = value;
	new_node->next = NULL;
	if(pos==1){
		new_node->next = *head;
		*head = new_node;
		return;

	}
    while(c<pos-1 && temp){
    	temp=temp->next;
    	c++;
    }

    if(temp==NULL){
    	cout<<"position doesn't exist<<endl";
    }else{
    	new_node->next=temp->next;
    	temp->next=new_node;

    }


}

int deleteNodeFirst(struct Node** head){
	struct Node* temp = *head;
	if(temp==NULL){
		return -1;
	}
    *head = temp->next;
    int deletedData = temp->data;
     free(temp);
     return deletedData;
}
void deleteList(struct Node** head){
	struct Node* temp;
	struct Node* curr = *head;
	while(*head){
		temp=curr;
		*head = (*head)->next;
		curr = *head;
		free(temp);

	}
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
	int choice, pos, value;
	bool loop = true;
	struct Node* head = NULL;
	while(loop){
		cout<<"Linked List Menu : "<<endl;
		cout<<"Press 1 to create : "<<endl;
		cout<<"Press 2 to traverse : "<<endl;
		cout<<"Press 3 to delete front node in : "<<endl;
		cout<<"Press 4 to insert at a position : "<<endl;
		cout<<"Press 5 to delete whole linked list : "<<endl;
		cout<<"Press 9 to exit : "<<endl;
		cout <<"Enter your choice - ";
		cin>>choice;
		switch(choice){
			case 1:
				if(head){
					cout<<"linked list already created";
				}else{
					head = createLinkedList();
				}
				break;
			case 2:
				traverse(head);
				break;
			case 3:
				deleteNodeFirst(&head);
				break;
			case 4:
				cout<<"enter value and position";
				cin>>value>>pos;
				insertAt(&head,pos,value);
				break;
			case 5:
				deleteList(&head);
				break;
			case 9:
				loop = false;
				break;
			default:
				cout<<"enter valid choice";
				break;
		}
	}
	return 1;
}

