class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> w(words.begin(), words.end());
        for(auto s: words) {
            for(int i = 1; i < s.size(); i++) {
                string t = s.substr(i);
                if(w.count(t)) w.erase(t);                
            }
        }
        int res = 0;
        for(string s: w) {
            res += s.size() + 1;            
        }
        
        return res;
    }
};