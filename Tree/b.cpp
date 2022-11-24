#include<iostream>

using namespace std;
#define SPACE 10
class Node {
    public:
        int data;
        Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node * makeTree() {
    return NULL;
}

Node * insert(Node *root, int data) {
    if(root == NULL) root = new Node(data);
    else {
        if(data < root->data) root->left = insert(root->left, data);
        else root->right = insert(root->right, data);
    }
    return root;
}

void printTree2D(Node *root, int space) {
    if(root == NULL) return;

    space += SPACE;
    printTree2D(root->right, space);
    cout << endl;
    for(int i = SPACE; i < space; i++) cout << " ";
    // cout << endl;
    cout << root->data << endl;
    printTree2D(root->left, space);
}

void printTree(Node *root) {
    if(root == NULL) return;
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

bool searchTree(Node* root, int data) {
    if(root == NULL) return false;
    if(root->data == data) return true;
    else {
        if(root->data > data) searchTree(root->left, data);
        else searchTree(root->right, data);
    }
}

int minValue(Node *root) {
    if(root->left == NULL) return root->data;

    else return minValue(root->left);
}

Node* deleteItem(Node *root, int data) {
    if(root == NULL) return root;
    else if(data < root->data) root->left = deleteItem(root->left, data);
    else if(data > root->data) root->right = deleteItem(root->right, data);

    else {
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            return root;
        }
        else if(root->left == NULL) {
            Node *temp = root;
            root = root->right;
            return root;
        }
        else if(root->right == NULL) {
            Node *temp = root;
            root = root->left;
            delete temp;

            return root;
        }
        else {
            int tempValue = minValue(root->right);
            root->data = tempValue;

            root->right = deleteItem(root->right, tempValue);

            return root;
        }
    }
}

int main() {

    Node *root;
    root = makeTree();
    int a[] = {7, 5, 6, 3, 4, 9, 8, 2, 1, 10};

    // insert data in the tree
    for(int i = 0; i < 10; i++) {
        root = insert(root, a[i]);
    }

    // Print the whole tree inOrder order
    printTree(root);
    cout << endl;

    // Search an element in the tree...
    // bool flag = searchTree(root, 11);
    // cout << flag << endl;
    printTree2D(root, SPACE);
    // delete a specif ic item from the tree
    deleteItem(root, 7);

    // printTree(root);
    // cout << endl;
    printTree2D(root, SPACE);

    return 0;
}