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
    bool isfine(ListNode* head) {
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        ListNode* cur = head;
        while(cur) {
            sum += cur->val;
            if(mp.find(sum) != mp.end()) return false;
            mp[sum]++;
            cur = cur->next;
        }
        return true;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(isfine(head)) return head;
        
        unordered_map<int, ListNode*> mp;
        int sum = 0;
        ListNode* cur = head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        mp[0] = dummy; 
        while(cur) {
            sum += cur->val;
            if(mp.find(sum) == mp.end()) {
                mp[sum] = cur;
            }
            else {
                mp[sum]->next = cur->next;
                cur->next = NULL;
            }
            cur = cur->next;
        }
        return removeZeroSumSublists(dummy->next);
    }
};