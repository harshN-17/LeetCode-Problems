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
    void solve(ListNode* head, stack<int>& st, vector<int>& res) {
        if(head == NULL) return;
        solve(head->next, st, res);
        // if(st.empty()) res.push(0);
        while(!st.empty() && st.top() <= head->val) {
            st.pop();
        }
        res.push_back(st.empty() ? 0 : st.top());
        st.push(head->val);
    }
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> res;
        solve(head, st, res);
        reverse(res.begin(), res.end());
        return res;
    }
};