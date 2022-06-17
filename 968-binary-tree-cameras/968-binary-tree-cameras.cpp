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
    int hasCamera = 0, underCamera = 1, needCamera = 2;
    int cameras = 0;    
    
    int dfs(TreeNode* root) {
        if(!root) return underCamera;
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        
        if(l == needCamera || r == needCamera) {
            cameras++;
            return hasCamera;
        }
        
        else if(l == hasCamera || r == hasCamera) {
            return underCamera;
        }
        else {
            return needCamera;
        }
    }
    int minCameraCover(TreeNode* root) {
        cameras += dfs(root) == needCamera ? 1 : 0;
        return cameras;
    }
};