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
    int dfs(TreeNode* root, int maxValue) {
        if(root == NULL) return 0;
        int res = 0;
        if(root->val >= maxValue) {
            maxValue = root->val;
            res++;
        }
        res += dfs(root->left, maxValue);
        res += dfs(root->right, maxValue);
        return res;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};