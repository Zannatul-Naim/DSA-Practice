#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

typedef Node node;

node* insert_bst(node *root, int data) {
    
    node *currentNode = root;
    node* tempNode = new Node(data);
     int loc = 1;
    while(currentNode != NULL) {
       
        if(currentNode->data > tempNode->data) {
            if(currentNode->left != NULL) {
                currentNode = currentNode->left;
                loc *= 2;
            }
            else {
                currentNode->left = tempNode;
                break;
            }
        }
        else if(currentNode->data < tempNode->data) {
            if(currentNode->right != NULL) {
                currentNode = currentNode->right;
                loc = loc*2 + 1;
            }
            else {
                currentNode->right = tempNode;
                break;
            }
        }
        else {
            cout << "found at : " << loc << endl;
            break;
        }
    }
    return root?root:tempNode;
}

void print2DUtil(node* root, int space) {
    
    if(root == NULL) return;
    
    space += 10;

    print2DUtil(root->right, space);
    cout << endl;
    for(int i = 10; i < space; i++) cout << " ";
    cout << root->data << endl;

    print2DUtil(root->left, space);
}

void printTree(node* root) {
    print2DUtil(root, 0);
}

void inOrder(node *root) {
    
    if(!root) return;
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    
    node *root = NULL;
    for(int i = 0; ; i++) {
        int x;
        cout << "Enter the data of node : ";
        cin >> x;
        // system("clear");
        if(x == -1) break;
        root = insert_bst(root, x);
        printTree(root);
        
    }

    cout << "\n\nInorder : ";
    inOrder(root);
    cout << endl;

    insert_bst(root, 14);
    printTree(root);

    return 0;
}