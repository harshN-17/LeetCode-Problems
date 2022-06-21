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
    void solve(TreeNode* root, map<int, map<int, vector<int>>>& mp, int d, int l) {
        if(root == NULL) return;
        mp[d][l].push_back(root->val);
        solve(root->left, mp, d - 1, l + 1);
        solve(root->right, mp, d + 1, l + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;
        solve(root, mp, 0, 0);
        vector<vector<int>> res;
        for(auto d: mp) {
            vector<int> temp;
            for(auto l: d.second) {
                sort(l.second.begin(), l.second.end());
                temp.insert(temp.end(), l.second.begin(), l.second.end());
            }
            res.push_back(temp);
            // n++;
        }
        return res;
    }
};