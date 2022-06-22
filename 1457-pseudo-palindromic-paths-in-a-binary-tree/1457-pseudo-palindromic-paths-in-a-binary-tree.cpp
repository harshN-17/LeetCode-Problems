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
    void solve(TreeNode* root, int &count, int p){
        if(root == NULL) return;
        p ^= 1 << (root->val - 1);
        if(root->left == NULL && root->right == NULL) {
            if((p & (p - 1)) == 0) count++;
        }
        solve(root->left, count, p);
        solve(root->right, count, p);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        solve(root, count, 0);
        return count;
    }
};