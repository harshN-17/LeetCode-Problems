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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<TreeNode*, TreeNode*> parents; 
        TreeNode* root = NULL;
        int n = desc.size();
        for(int i = 0; i < n; i++) {
            TreeNode* parent;
            if(mp.find(desc[i][0]) == mp.end()) {
                parent = new TreeNode(desc[i][0]);
                mp[desc[i][0]] = parent;
            }
            parent = mp[desc[i][0]];
            TreeNode* child;
            if(mp.find(desc[i][1]) == mp.end()) {
                child = new TreeNode(desc[i][1]);
                mp[desc[i][1]] = child;
            }
            child = mp[desc[i][1]];
            if(desc[i][2]) parent->left = child;
            else parent->right = child;
            parents[child] = parent;
        }
        root = parents.begin()->second;
        while(parents.find(root) != parents.end()) {
            root = parents[root];
        }
        return root;
    }
};