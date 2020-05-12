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

class node{
    public:
        int data;
        node*left;
        node*right;
    
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(){
    //base case
    int d;
    cin>>d;

    if(d == -1) return NULL;

    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void print(node *root){
    if(root == NULL){
        return;
    }

    //otherwise print root followed by subtrees
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);

}

int main() {
    node* root = buildTree();
    print(root);
}
