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
    int len(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp) {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL) return head;
        k %= len(head);
        if(k == 0) return head;
        ListNode* slow = head, *fast = head, *tail;
        while(fast && k--) {
            fast = fast->next;
        }
        while(fast && fast->next) {
            slow = slow->next;
            // tail = fast;
            fast = fast->next;
        }
        ListNode* newHead = slow->next;
        slow->next = NULL;
        fast->next = head;
        return newHead;
    }
};