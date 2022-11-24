#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class Tree {
    public:
    int data;
    Tree *left, *right;
    Tree(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// Tree *root = NULL;

Tree* make_Tree(Tree *root, int data) {
    if(root == NULL) {
        root = new Tree(data);
        return root;
    }
    queue<Tree*> q_tree;

    q_tree.push(root);
    while(!q_tree.empty()) {
        Tree *temp = q_tree.front();
        q_tree.pop();

        if(!temp->left) {
            temp->left = new Tree(data);
            break;
        }
        else if(!temp->right) {
            temp->right = new Tree(data);
            break;
        }
        else {
            q_tree.push(temp->left);
            q_tree.push(temp->right);
        }
    }
    return root;
}

void inorder(Tree *root) {

    if(root == NULL) return;

    stack<Tree*> stk_tree;

    // stk_tree.push(root);
    Tree *temp = root;

    while(!stk_tree.empty() || temp != NULL) {
        
        while(temp!= NULL) {
            stk_tree.push(temp);
            temp = temp->left;
        }
        temp = stk_tree.top();
        cout << temp->data << " ";
        stk_tree.pop();

        temp = temp->right;
    }
    cout << endl;
}

int main() {

    Tree* root = NULL;

    int data[] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 9; i++) root = make_Tree(root, data[i]);

    cout << "In Order : ";
    inorder(root);

    return 0;

}