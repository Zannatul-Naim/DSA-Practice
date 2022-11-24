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

Tree *root = NULL;

void make_Tree(int data) {
    if(root == NULL) {
        root = new Tree(data);
        return ;
    }
    queue<Tree*> q_tree;

    q_tree.push(root);
    while(!q_tree.empty()) {
        Tree *temp = q_tree.front();
        q_tree.pop();

        if(!temp->left) {
            temp->left = new Tree(data);
            return;
        }
        else if(!temp->right) {
            temp->right = new Tree(data);
            return;
        }
        else {
            q_tree.push(temp->left);
            q_tree.push(temp->right);
        }
    } 
}

void preOrder() {
    if(root == NULL) return;

    stack<Tree*> stk_tree;
    stk_tree.push(root);

    while(!stk_tree.empty()) {
        Tree *temp = stk_tree.top();
        stk_tree.pop();

        cout << temp->data << " ";

        if(temp->right) stk_tree.push(temp->right);
        if(temp->left) stk_tree.push(temp->left);
    }
}

int main() {

    int data[] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 9; i++) make_Tree(data[i]);

    preOrder();

    return 0;

}