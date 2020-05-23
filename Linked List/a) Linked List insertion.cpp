/*
   Linked List 
       --insertion at head
       --insertion at tail
       --insertion in middle

   
   We are not declaring like this 
         node n;
         n.next = NULL;
   because this is a static allocation and as soon as the function call is over it will get deleted.


   Generally node consists of data and next. To update data we will write (*n).data
   a shortcut to write this is n -> data
   Similarily for (*n).next ===== n -> next

*/

#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node* next;
    
    //constructor
    node(int d) {
        data = d;
        next = NULL;
    }
};

void insertAtTail(node*& head,int data) {
    if(head == NULL){
        head = new node(data);
        return;
    }
    node* tail = head;
    while(tail -> next != NULL) {
        tail = tail -> next;
    }

    tail -> next = new node(data);
    return;
}

void insertAtHead(node*&head,int data) {
    node* n = new node(data);
    n -> next = head;
    head = n;
}

void printLinkedList(node* head) {
    node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout<<endl;
}

int length(node* head) {
    int len = 0;

    node* temp = head;
    while(temp -> next != NULL) {
        temp = temp -> next;
        len += 1;
    }

    return len;
}

void insertInMiddle(node*& head,int data,int pos) {
    if(head == NULL || pos == 0) {
        insertAtHead(head,data);
    }
    else if( pos > length(head) ) {
        insertAtTail(head,data);
    }
    else {
        //jump pos-1 positions
        int jump = 1;
        node* temp = head;
        while(jump <= pos-1) {
            temp = temp -> next;
            jump += 1;
        }

        node* n = new node(data);
        n -> next = temp -> next;
        temp -> next = n;

    }
}

int main() {
    node* head = NULL;
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,2);
    insertAtHead(head,1);

    insertInMiddle(head,3,2);
    insertAtTail(head,7);

    printLinkedList(head);
}
