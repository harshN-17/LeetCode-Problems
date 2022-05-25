class Solution {
public:
    int dp[301];
    bool solve(string s, vector<string>& wordDict, int index){
        if(s.size()<=index){
            return true;
        }
        if(dp[index] != -1) return dp[index];
        for(int i=index+1; i<=s.size(); i++){
            string left = s.substr(index,i-index);
            // cout<<i<<' '<<left<<' '<<s<<' '<<endl;
            if(find(wordDict.begin(), wordDict.end(), left) != wordDict.end()){
                    if(solve(s, wordDict, i)){
                        dp[index] = 1;
                        return true;
                    }
                }
            }
        dp[index] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        return solve(s,wordDict,0);
    }
};