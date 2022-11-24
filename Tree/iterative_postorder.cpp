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

void postorder(Tree *root) {
    if(root == NULL) return;

    stack<Tree*> stk_tree, temp_stk;
    stk_tree.push(root);

    while(!stk_tree.empty()) {
        Tree *temp = stk_tree.top();
        stk_tree.pop();

        temp_stk.push(temp);
        
        if(temp->left) stk_tree.push(temp->left);
        if(temp->right) stk_tree.push(temp->right);
    }

    while(!temp_stk.empty()) {
        cout << temp_stk.top()->data << " ";
        temp_stk.pop();
    }
    cout << endl;
}

int main() {

    Tree* root = NULL;

    int data[] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 9; i++) root = make_Tree(root, data[i]);

    cout << "Post Order : ";
    postorder(root);

    return 0;

}