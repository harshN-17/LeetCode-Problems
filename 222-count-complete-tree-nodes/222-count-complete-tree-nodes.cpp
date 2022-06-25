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
    int height(TreeNode* root) {
        if(root == NULL) return -1;
        return 1 + height(root->left);
    }
    int countNodes(TreeNode* root) {
        //calculate the height of entire treegf
        int h  = height(root);
        if(h == -1) return 0;
        //calculate height of right subtree
        int rightHeight = height(root->right);
        //if right subtree has height one less than the entire tree 
        //it means last node exist on the last row of this subtree
        //then the number of nodes in total will be 
        //all the left subree nodes (2^h)-1 + the root node + recursively finding the right subtree nodes
        if(h - 1 == rightHeight) {
            return (1 << h) + countNodes(root->right);
        }
        //otherwise the last leaf node exist in left subtree and right subtree is 
        //full up till the height h-2
        //therefore the total node is 2^(h-1) - 1 + a root node + recursively count all left subtree nodes
        else {
            return (1 << (h-1)) + countNodes(root->left);
        }
    }
};