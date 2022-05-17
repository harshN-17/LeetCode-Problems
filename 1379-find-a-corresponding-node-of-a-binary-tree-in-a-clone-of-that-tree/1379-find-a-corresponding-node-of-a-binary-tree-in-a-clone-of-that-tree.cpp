/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == target) return cloned;
        if(!cloned or !original) return NULL;
        
        TreeNode* t1 = getTargetCopy(original->left, cloned->left, target);
        TreeNode* t2 = getTargetCopy(original->right, cloned->right, target);
        
        if(t1) return t1;
        if(t2) return t2;
        
        return NULL;
    }
};