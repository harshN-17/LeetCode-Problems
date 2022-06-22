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
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL, *first = NULL, *second = NULL;
        TreeNode* cur = root;
        TreeNode* pred = NULL;
        while(cur != NULL) {
            if(prev && prev->val >= cur->val) {
                if(first == NULL) first = prev;
                second = cur;
            }
            
            if(cur->left) {
                pred = cur->left;
                while(pred->right != NULL && pred->right != cur) {
                    pred = pred->right;
                }
                if(pred->right == cur) {
                    pred->right = NULL;
                    prev = cur;
                    cur = cur->right;
                }
                else {
                    pred->right = cur;
                    cur = cur->left;
                }
            }
            else {
                prev = cur;
                cur = cur->right;
            }
        }
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};