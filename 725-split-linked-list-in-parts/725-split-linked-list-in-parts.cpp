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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while(cur) {
            n++;
            cur = cur->next;
        }
        vector<ListNode*> res(k);
        cur = head;
        int size = n/k, extra = n%k;
        for(int i = 0; i < k && cur != NULL; i++) {
            res[i] = cur;
            for(int j = 0; j < size + ((extra > 0) ? 1 : 0) - 1; j++) {
                cur =  cur->next;                
            }
            ListNode* temp = cur;
            if(cur!=NULL) cur = cur->next;
            if(temp!=NULL) temp->next = NULL;
            extra--;
        }
        return res;
    }
};