/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void preOrder(TreeNode *p, vector < int > &v) {
        if(p == nullptr) v.push_back(-1000000);
        if(p == NULL) return;
        v.push_back(p->val);
        preOrder(p->right, v);
        preOrder(p->left, v);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector < int > x, y;

        preOrder(p, x);
        preOrder(q, y);

        if(x.size() != y.size()) return false;
        for(int i = 0; i < x.size(); i++) {
            if(x[i] != y[i]) return false;
        } 
        return true;

    }
};
