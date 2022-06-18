class WordFilter {
public:
    unordered_map<string, int> dict;
    WordFilter(vector<string>& words) {
        for(int k = 0; k < words.size(); k++){
            int n = words[k].size();
            for(int i = 1; i <= n; i++) {
                string pre = words[k].substr(0, i);
                for(int j = 0; j < n; j++) {
                    string suf = words[k].substr(j);
                    dict[pre  + "|" + suf] = k;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {        
        return dict.find(prefix + "|" + suffix) == dict.end() ? -1 : dict[prefix + "|" + suffix];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */