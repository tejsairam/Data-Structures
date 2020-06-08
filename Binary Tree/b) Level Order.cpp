#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

        node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree() {

    int d;
    cin >> d;

    if(d == -1) {
        return NULL;
    }

    node* root = new node(d);
    root -> left = buildTree();
    root -> right = buildTree();
    return root;
}

void printTree(node* root) {
    if(root == NULL) return;

    cout << root -> data <<" ";
    printTree(root -> left);
    printTree(root -> right);
}

int height(node* root) {

    if(root == NULL) return 0;

    int ls = height(root -> left);
    int rs = height(root -> right);

    return max(ls,rs) + 1;
}

void kthLevel(node* root, int k) {
    if(root == NULL) {
        return;
    }

    if(k == 1) {
        cout << root -> data << " ";
        return;
    }

    kthLevel(root -> left,k-1);
    kthLevel(root -> right,k-1);
    return;
}

void printAllLevels(node* root) {
    

    int H = height(root);
    for(int i = 1; i <= H; ++i) {
        kthLevel(root,i);
        cout << endl;
    }
    return;
    
}

int main() {
    node* root = buildTree();
    printTree(root);

    cout << endl;

    cout << height(root) << endl;

    kthLevel(root,3);

    cout << endl;
    
    printAllLevels(root);
    return 0;
}
