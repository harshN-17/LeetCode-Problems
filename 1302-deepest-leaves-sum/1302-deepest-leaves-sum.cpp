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
    void solve(TreeNode* root, int level, int &maxlevel, int &sum){
        if(root==NULL) return;
        if(level>maxlevel){
            maxlevel = level;
            sum = 0;
        }
        if(level==maxlevel) sum +=root->val;
        
        solve(root->left,level+1,maxlevel,sum);
        solve(root->right,level+1,maxlevel,sum);        
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum=0, maxlevel=0;
        solve(root,0,maxlevel,sum);
        return sum;
    }
};