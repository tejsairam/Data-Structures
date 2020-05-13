/*
   Binary Tree
     -- Hierarchical data structure
     -- every node will have atmost 2 children
     -- sibling means children of the same parent
     -- leaf nodes are nodes with 0 children


    ALgorithm would be build the root and recursively build left and right subtrees

*/

#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(){
    int d;
    cin>>d;

    //base case
    if(d == -1) return NULL;

    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void print(node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

void printPost(node* root){
    if(root == NULL) return;

    printPost(root->left);
    cout<<root->data<<" ";
    
    printPost(root->right);
}

void printIn(node* root){
    if(root == NULL) return;

    printIn(root->left);
    printIn(root->right);
    cout<<root->data<<" ";
}
int main() {
    node* root = buildTree();
    print(root);
    cout<<endl;
    
    printPost(root);
    cout<<endl;
    
    printIn(root);

}
