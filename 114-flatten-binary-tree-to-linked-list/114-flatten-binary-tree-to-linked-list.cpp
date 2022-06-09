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
    void getPreOrder(TreeNode* root, queue<TreeNode*>& q) {
        if(root == NULL) return;
        q.push(root);
        getPreOrder(root->left, q);
        getPreOrder(root->right, q);
    }
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        queue<TreeNode*> q;
        getPreOrder(root, q);
        q.pop();
        TreeNode* temp = root;
        while(!q.empty()) {
            temp->right = q.front();
            q.pop();
            temp->left = NULL;
            temp = temp->right;
        } 
    }
};