/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int findLength(ListNode *head) {
        ListNode* temp = head;
        int l=0;
        while(temp){
            temp = temp->next;
            l++;
        }
        return l;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = findLength(headA);
        int l2 = findLength(headB);
        
        if(l1<l2) return getIntersectionNode(headB, headA);
        
        ListNode* t1 = headA, *t2 = headB;
        while(l1 > l2) {
            t1 = t1->next;
            l1--;
        }
        
        while(t1 and t2) {
            if(t1 == t2) return t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        
        return NULL;
    }
};