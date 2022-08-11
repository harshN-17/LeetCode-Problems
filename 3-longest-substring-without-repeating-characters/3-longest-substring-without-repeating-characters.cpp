class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i = 0, j = 0;
        int len = 0;
        while(i < s.size() && j < s.size()) {
            if(!st.count(s[j])) {
                st.insert(s[j]);
                j++;
                len = max(len, j - i);
            }
            else {
                st.erase(s[i]);
                i++;
            }
        }
        return len;
    }
};