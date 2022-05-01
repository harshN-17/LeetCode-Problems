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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        long ans = 0;
        while(!q.empty()){
            int n = q.size();
            long x = q.front().second;
            long first, last;
            for(int k=0;k<n;k++){
                TreeNode* t = q.front().first;
                long i = q.front().second - x;
                q.pop();
                
                if(k==0) first = i;
                if(k==n-1) last = i;
                
                if(t->left) q.push({t->left,2*i+1});
                if(t->right) q.push({t->right,2*i+2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};