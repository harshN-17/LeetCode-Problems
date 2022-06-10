class Solution {
public:
    vector<int> findnsl(vector<int> v, int n){
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                while(!st.empty() and v[st.top()]>=v[i]) st.pop();
                if(st.empty()) ans[i] = -1;
                else ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    
    vector<int> findnsr(vector<int> v, int n){
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans[i] = n;
            }
            else{
                while(!st.empty() and v[st.top()]>=v[i]) st.pop();
                if(st.empty()) ans[i] = n;
                else ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();        
        int ans =0;
        vector<vector<int>> dp(n, vector<int>(m,0));
        
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size() ; j++) {
                dp[i][j] = matrix[i][j]-'0';
                if (dp[i][j] > 0 && i>0) dp[i][j] += dp[i - 1][j];
            }
        }
        
        for(int i=0; i<n;i++){
            vector<int> nsl = findnsl(dp[i],m);
            vector<int> nsr = findnsr(dp[i],m);
            for(int j=0;j<m;j++){
                // if(i and dp[i][j] != 0) dp[i][j]= ;
                
                ans = max(ans, (dp[i][j]) * (nsr[j]-nsl[j]-1));
            }
        }
        return ans;
    }
};