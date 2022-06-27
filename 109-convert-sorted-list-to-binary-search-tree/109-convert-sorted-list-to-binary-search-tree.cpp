/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* findMiddle(ListNode* head, ListNode* last) {
        ListNode* slow = head, *fast = head;
        while(fast != last && fast->next != last) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    TreeNode* solve(ListNode*head, ListNode* last) {
        if(head == last) return NULL;
        TreeNode* root = new TreeNode();
        ListNode* mid = findMiddle(head, last);
        root->val = mid->val;
        root->left = solve(head, mid);
        root->right = solve(mid->next, last);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head, NULL);
    }
};