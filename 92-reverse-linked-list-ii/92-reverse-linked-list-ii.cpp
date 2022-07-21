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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right) return head;
        ListNode* prev = NULL, *cur = head;
        while(left > 1) {
            prev = cur;
            cur = cur->next;
            left--; right--;
        }
        ListNode* first = prev, *last = cur;
        ListNode* nxt;
        while(right) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            right--;
        }
        if(first) first->next = prev;
        else head = prev;
        last->next = cur;
        
        return head;
    }
};