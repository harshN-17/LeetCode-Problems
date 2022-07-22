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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = NULL, *cur = head, *right = head;
        while(cur && cur->val < x) {
            left = cur;
            cur = cur->next;
        }
        while(cur) {
            if(cur->val >= x) {
                right = cur;
                cur = cur->next;
            }
            else {
                ListNode* temp = cur;
                cur = cur->next;
                right->next = cur;
                if(left) {
                    temp->next = left->next;
                    left->next = temp;
                }
                else {
                    temp->next = head;
                    head = temp;
                }
                left = temp;
            }
        }
        return head;
    }
};