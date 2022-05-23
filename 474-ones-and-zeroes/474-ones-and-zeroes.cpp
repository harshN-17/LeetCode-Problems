class Solution {
public:
    int dp[601][101][101];
    int noOfSetBits(string s){
        int cnt=0;
        for(char c: s){
            if(c=='1') cnt++;
        }
        return cnt;
    }
    
    int solve(vector<pair<int, int>>& v, int index, int n, int m){
        if(index==v.size() or (n==0 and m==0)) return 0;
        
        if(dp[index][n][m] != -1) return dp[index][n][m];
        
        if(n<v[index].first or m<v[index].second) return dp[index][n][m] = solve(v, index+1, n,m);
        
        int include = 1 + solve(v, index+1, n - v[index].first, m - v[index].second);
        int exclude = solve(v, index+1, n, m);
        
        return dp[index][n][m] = max(include, exclude);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        memset(dp, -1, sizeof(dp));
        vector<pair<int,int>> v(s);
        for(int i=0; i<s; i++){
            int n1 = noOfSetBits(strs[i]);
            int n2 = strs[i].size()-n1;
            v[i] = {n2,n1};
            cout<<n1<<' '<<n2<<endl;
        }
        return solve(v, 0, m, n);
    }
};