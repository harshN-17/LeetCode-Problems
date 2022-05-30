class Solution {
public:
    void solve(string s, vector<string> &wordDict, vector<string> &res, string t, int index){
        //base-case
        if(s.size()<=index){
            t.pop_back();
            res.push_back(t);
        }
        
        for(int i=index+1; i<=s.size(); i++){
            string left = s.substr(index,i-index);
            if(find(wordDict.begin(), wordDict.end(), left)!=wordDict.end()){
                solve(s, wordDict, res, t+left+" ", i);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        solve(s, wordDict, res, "", 0);
        return res;
    }
};