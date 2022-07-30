class Solution {
public:
    vector<int> counter(string s) {
        vector<int> t(26);
        for(char c: s) t[c-'a']++;
        return t;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> count(26);
        for(string b: words2) {
            vector<int> t = counter(b);
            for(int i = 0; i < 26; i++) {
                count[i] = max(count[i], t[i]);
            }
        }
        vector<string> res;
        for(string a: words1) {
            vector<int> t = counter(a);
            int i;
            for(i = 0; i < 26; i++) {
                if(t[i] < count[i]) break;
            }
            if(i == 26) res.push_back(a);
        }
        return res;
    }
};