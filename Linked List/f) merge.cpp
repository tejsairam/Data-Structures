/*
    GETTING SEGMENTATION FAULT CHECK LATER
    
    Merge Sort
       -- sorting an unsorted linked list

    1) Break at mid (divide and conquer)
    2) Sort the smaller linked list (recursion)
    3) merge the sorted parts

    time complexity -> O(NLOGN)
    
    4 -> 1 -> 2 -> 0 -> 7 ->5   === 4 -> 1 -> 2 
                                       == 4 -> 1
                                           = 4
                                           = 1
                                       == 2 
                                
                                === 0 -> 7 -> 5
                                       == 0 -> 7
                                           = 0
                                           = 7
                                       == 5

*/

#include<iostream>
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

void insertAtTail(node*& head,int data) {
    if(head == NULL) {
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

void printLinkedList(node*& head) {
    node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void buildList(node*& head) {
    int data;
    cin >> data;

    while(data != -1) {
        insertAtTail(head,data);
        cin >> data;
    }
}

node* midPoint(node*& head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    node* fast = head -> next;
    node* slow = head;

    while(fast != NULL || fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

node* merge(node*& a,node*& b) {
    if(a == NULL) return b;
    if(b == NULL) return a;

    node* c;
    if(a->data < b->data) {
        c = a;
        c -> next = merge(a->next,b);
    }
    else {
        c = b;
        c -> next = merge(a,b->next);
    }
    return c;
}

node* mergeSort(node*& head) {
    node* mid = midPoint(head);

    node* a = head;
    node* b = mid -> next;
    mid -> next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    node* c = merge(a,b);

    return c;
}

istream& operator>>(istream& is,node*& head) {
    buildList(head);
    return is;
}

ostream& operator<<(ostream& os,node*& head) {
    printLinkedList(head);
    return os;
}

int main() {
    node* head = NULL;

    cin >> head;
    cout << head;

    cout << endl;
    head = mergeSort(head);

    cout << head;
    return 0;

}
