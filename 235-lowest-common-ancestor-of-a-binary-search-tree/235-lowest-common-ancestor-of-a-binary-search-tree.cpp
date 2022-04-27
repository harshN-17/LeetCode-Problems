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
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return root;
        if(p->val <= root-> val and q->val >= root->val) return root;
        
        else if(p->val > root->val) return lowestCommonAncestor(root->right,p,q);
        else return lowestCommonAncestor(root->left, p, q);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val){
            TreeNode* t = p;
            p = q;
            q = t;
        }        
        return solve(root,p,q);
    }
};