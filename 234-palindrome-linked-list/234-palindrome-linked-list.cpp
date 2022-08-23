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
class Solution {
public:
    bool check(ListNode** lhead, ListNode* rhead) {
        if(rhead == NULL) return true;
        bool flag = check(lhead, rhead->next);
        if(!flag) return false;
        if((*lhead)->val != rhead->val) return false;
        *lhead = (*lhead)->next;
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        return check(&head, head);
    }
};