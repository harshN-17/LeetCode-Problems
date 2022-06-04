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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head, *prev=NULL, *nxt ;
        int i=k, c=0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            c++;
        }
        
        if(c<k) return head;
        
        while(cur and k--) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        
        if(cur) head->next = reverseKGroup(cur, i);
        return prev;
    }
};