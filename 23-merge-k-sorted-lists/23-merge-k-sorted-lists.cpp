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

//8130057516
class Solution {
public:
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* d = dummy;
        while(l1 and l2) {
            if(l1->val < l2->val) {
                d->next = l1;
                l1 = l1->next; 
            }
            else {
                d->next = l2;
                l2 = l2->next;
            }
            d = d->next;            
        }
        while(l1){
            d->next = l1;
            l1 = l1->next;
            d = d->next;
        }
        while(l2){
            d->next = l2;
            l2 = l2->next;
            d = d->next;
        }
        return dummy->next;
    }
    
    ListNode* mergeK(vector<ListNode*>& lists, int start, int end) {
        if(start == end) return lists[start];
        if(start == end - 1) return mergeList(lists[start], lists[end]);
        
        int mid = start + (end - start) / 2;
        ListNode* left = mergeK(lists, start, mid);
        ListNode* right = mergeK(lists, mid + 1, end);
        return mergeList(left, right);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        
        return mergeK(lists, 0, n - 1);
    }
};