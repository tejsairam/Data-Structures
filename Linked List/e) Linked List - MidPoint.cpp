/*
     Finding Mid Point in linked list

     for odd length,
          1 --> 2 --> 3 --> 4 --> 5    mid point = 3
    
     for even length there are 2 mid points,
          1 --> 2 --> 3 --> 4         mid point1 = 2, mid point2 = 3 here we can find any mid point

    
    For findng mid point we will use Runner Technique 
              -- i.e. we will keep 2 pointers one is fast pointer and other is slow pointer
              -- fast can end up at last position or can end up at NULL

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




void printLinkedList(node* head){
    node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
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


void buildList(node*& head) {
    int data;
    cin >> data;

    while(data != -1){
        insertAtTail(head,data);
        cin >> data;
    }
}

node* midPoint(node*& head) {
    if(head == NULL || head -> next == NULL){
        return head;
    }

    node* fast = head -> next;
    node* slow = head;

    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

istream& operator>>(istream& is, node*& head) {
    buildList(head);
    return is;
}

ostream& operator<<(ostream& os, node*& head){
    printLinkedList(head);
    return os;
}
int main(){
    node* head = NULL;
    node* head2 = NULL;

    cin >> head >> head2;
    cout << head << endl << head2 << endl;

    node* m1 = midPoint(head);
    cout << m1 -> data << endl;

    node* m2 = midPoint(head2);
    cout << m2 -> data << endl;

    return 0;
}
