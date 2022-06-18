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
    unordered_map<int, vector<TreeNode*>> memo;
    
    vector<TreeNode*> allPossibleFBT(int n) {   
        if(memo.find(n) != memo.end()) return memo[n];
        vector<TreeNode*> res;
        if(n == 1) {
            res.push_back(new TreeNode());
        }
        for(int i = 1; i < n; i += 2) {
            int l = i, r = n - i - 1;
            vector<TreeNode*> r1 = allPossibleFBT(l);
            vector<TreeNode*> r2 = allPossibleFBT(r);
            for(auto it: r1) {
                for(auto it2: r2) {
                    TreeNode* root = new TreeNode();
                    root->left = it;
                    root->right = it2;
                    res.push_back(root);
                }
            }
        }
        return memo[n] = res;
    }
};