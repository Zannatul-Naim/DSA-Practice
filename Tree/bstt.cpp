#include<iostream>
using namespace std;

#define SPACE 10

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

typedef Node node;

node *root = NULL;
int loc;

void insert(int data) {
    if(root == NULL) {
        root = new Node(data);
        return;
    }
    node *temp = root;
    loc = 1;
    while(temp != NULL) {
        if(temp->data > data) {
            if(temp->left != NULL) {
                temp = temp->left;
                loc *= 2;
            }
            else {
                temp->left = new Node(data);
                return;
            }
        }
        else if(temp->data < data) {
            if(temp->right != NULL) {
                temp = temp->right;
                loc = loc*2 + 1;
            }
            else {
                temp->right = new Node(data);
                return;
            }
        }
        else {
            cout << "Found at pos : " << loc << endl;
            return;
        }
    }
}

void printTree(node *root, int space) {
    if(root == NULL) return;

    space += SPACE;
    printTree(root->right, space);
    cout << endl;
    for(int i = SPACE; i < space; i++) cout << " ";
    // cout << endl;
    cout << root->data << endl;
    printTree(root->left, space);
}

int minNodeValue(node *root) {
    if(root->left == NULL) return root->data;
    return minNodeValue(root->left);
}

node* deleteNodeValue(node *root, int value) {
    
    if(root == NULL) return root;
    else if(value < root->data) root->left = deleteNodeValue(root->left, value);
    else if(value > root->data) root->right = deleteNodeValue(root->right, value);

    else {
        if(root->left == NULL && root->right == NULL) return NULL;
        else if(root->left == NULL) {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            node *temp = root->left;
            free(root);
            return temp;
        }
        int minValue = minNodeValue(root->right);
        root->data = minValue;
        root->right = deleteNodeValue(root->right, minValue);
    }
    return root;
}

void inorder(node *root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    while(true) {
        cout <<"Enter node (-1 for exit): ";
        int x;
        cin >> x;
        if(x == -1) break;
        insert(x);
//         inorder(root);
        printTree(root, 10);
        cout << endl;
    }

    printTree(root, SPACE);

    cout << "Enter a value to delete : ";
    int x;
    cin >> x;

    root = deleteNodeValue(root, x);
    printTree(root, SPACE);

    cout << "Inorder result : ";
    inorder(root);

    return 0;
}