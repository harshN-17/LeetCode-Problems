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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()) {
            int size = q.size();
            res = q.front()->val;
            while(size--) {
                auto it = q.front();
                q.pop();
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
        }
        return res;
    }
};