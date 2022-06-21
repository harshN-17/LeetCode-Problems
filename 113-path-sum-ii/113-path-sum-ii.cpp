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
    void solve(TreeNode* root, int target, vector<vector<int>>& res, vector<int> temp, int sum) {
        if(root == NULL) return;
        sum += root->val;
        if(!root->left && !root->right && target == sum) {
            temp.push_back(root->val);
            res.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        solve(root->left, target, res, temp, sum);
        solve(root->right, target, res, temp, sum);        
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        solve(root, targetSum, res, {}, 0);
        return res;
    }
};