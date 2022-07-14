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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &preIndex, int left, int right) {
        if(left > right) return NULL;
        TreeNode* root = new TreeNode(preorder[preIndex]);
        int i = left;
        while(inorder[i] != preorder[preIndex]) i++;
        preIndex++;
        root->left = helper(preorder, inorder, preIndex, left, i - 1);
        root->right = helper(preorder, inorder, preIndex, i + 1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preIndex = 0;
        return helper(preorder, inorder, preIndex, 0 , n - 1);
    }
};