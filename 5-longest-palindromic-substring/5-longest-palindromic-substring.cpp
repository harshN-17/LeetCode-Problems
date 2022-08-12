class Solution {
public:
    int findLength(string &s, int l, int r) {
        while(l >= 0 && r < s.size() && s[l] == s[r] ) {
            l--; r++;
        }
        return r - l - 1;
    }
    string longestPalindrome(string s) {
        int n = s.size(), i = 0;
        int l = 0, r = 0;
        string res = "";
        while(i < n) {
            int l1 = findLength(s, i, i);
            int l2 = findLength(s, i, i + 1);
            int len = max(l1, l2);
            if(len > r - l + 1) {
                l = i - (len - 1) / 2;
                r = i + len / 2;
            }
            i++;
        }
        return s.substr(l, r - l + 1);
    }
};