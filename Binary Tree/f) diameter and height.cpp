/*
diameter of tree is longest distance between any two nodes
       8
    /     \
   10      3
  /  \       \
 1    6       7
     / \     /
    9   1   13

So, in the above tree longesr distance is between node 1 and node 13 

Do post order traversal to optimise the solution

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
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}



int height(node*root){
    if(root==NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs) + 1;

}

int count(node*root){
    if(root==NULL){
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

int diameter(node* root) { //time limit exceeded so optimize it
    if(root == NULL) return 0;

    int h1 = height(root -> left);
    int h2 = height(root -> right);
    int op1 = h1 + h2;
    int op2 = diameter(root -> left);
    int op3 = diameter(root -> right);

    return max(op1,max(op2,op3));
}

class Pair {
    //we can also use inbuilt pair stl but these terms will be easier for coding
    public:
        int height;
        int diameter; 
};

Pair fastDiameter(node* root) {
    Pair p;
    if(root == NULL) {
        p.diameter = p.height = 0;
        return p;
    } 
    //otherwise
    Pair left = fastDiameter(root -> left);
    Pair right = fastDiameter(root -> right);

    p.height = max(left.height,right.height) + 1;
    p.diameter = max(left.height+right.height, max(left.diameter,right.diameter));
    return p;

}

int main(){ 
    node* root = buildTree();
    //cout << diameter(root) << endl;

    Pair p = fastDiameter(root);
    cout << p.height << endl;
    cout << p.diameter << endl;


return 0;
}










