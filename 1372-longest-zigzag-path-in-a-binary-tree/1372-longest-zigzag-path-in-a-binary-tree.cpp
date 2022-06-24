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
    vector<int> solve(TreeNode* root, int& res) {
        if(root == NULL) return {-1, -1};
        int left = solve(root->left, res)[1] + 1;
        int right = solve(root->right, res)[0] + 1;
        res = max(res, max(left, right));
        
        return {left, right};
    }
    int longestZigZag(TreeNode* root) {
        int res = 0;
        solve(root, res);
        return res;
    }
};