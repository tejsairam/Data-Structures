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

class node{
    public:
        int data;
        node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};


void insertAtHead(node*&head,int data){
    node* n = new node(data);
    n -> next = head;
    head = n;
}

void printLinkedList(node* head){
    node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int length(node* head){
    int len = 0;
    node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
        len += 1;
    }

    return len;
}

void insertAtTail(node*& head,int data){
    if(head == NULL){
        head = new node(data);
        return;
    }

    node* tail = head;

    while(tail->next != NULL){
        tail = tail->next;
    }

    tail->next = new node(data);
    return;


}

void insertInMiddle(node*& head,int data,int pos){
    if(head == NULL || pos == 0){
        insertAtHead(head,data);
    }
    else if(pos > length(head)){
        insertAtTail(head,data);
    }
    else{
        int jump = 1;
        node* temp =head;

        while(jump <= pos-1){
            temp = temp->next;
            jump += 1;
        }

        node* n = new node(data);
        n -> next = temp -> next;
        temp -> next = n;

    }
}

void deleteAtHead(node*& head){
    if(head == NULL) return;

    node* temp = head;
    head = head -> next;
    delete temp;
    return;
}

void deleteAtTail(node*& head){
    node* prev = NULL;
    node* temp = head;

    while(temp->next != NULL){
        prev = temp;
        temp = temp -> next;
    }

    delete temp;
    prev -> next = NULL;
    return;
}

void deleteInMiddle(node*& head,int pos) {
    if(head == NULL || pos == 0){
        return;
    }
    else if(pos > length(head)){
        deleteAtTail(head);
    }
    else{
        node* prev = NULL;
        node* temp = head;

        int jump = 1;
        while(jump <= pos-1){
            prev = temp;
            temp = temp -> next;
            jump += 1;
        }

        prev->next = temp ->next;
        delete temp;
        return;
    }
}

bool searchRecursive(node*& head,int key){
    //base case
    if(head == NULL) return false;

    else if(head -> data == key) {
        return true;
    }
    else{
        return searchRecursive(head->next,key);
    }
}

bool searchIterative(node*& head,int key){
    if(head == NULL) return false;

    node* temp = head;
     while(temp != NULL){
         if(temp -> data == key) return true;
         temp = temp -> next;
     }

     return false;
}
int main(){
    node* head = NULL;
    insertAtHead(head,50);
    insertAtHead(head,40);
    insertAtHead(head,20);
    insertAtHead(head,10);

    printLinkedList(head);

    insertInMiddle(head,30,2);

    printLinkedList(head);

    insertAtTail(head,60);
    insertAtTail(head,70);

    printLinkedList(head);

    deleteAtHead(head);

    printLinkedList(head);

    deleteAtTail(head);
    printLinkedList(head);

    deleteInMiddle(head,3);
    printLinkedList(head);

    if(searchRecursive(head,20)){
        cout<<"Element is present! "<< endl;
    }
    else{
        cout<<"Element is not present" << endl;
    }

    if(searchIterative(head,10)){
        cout<<"element is present" << endl;
    }
    else{
        cout<<"element is not present" << endl;
    }
}
