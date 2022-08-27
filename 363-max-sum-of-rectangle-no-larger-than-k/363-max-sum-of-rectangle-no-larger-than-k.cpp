class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size(), cols = matrix[0].size();
        int res = INT_MIN;
        for(int i = 0; i < cols; i++) {
            vector<int> prefix(rows);
            for(int j = i; j < cols; j++) {
                for(int k = 0; k < rows; k++) {
                    prefix[k] += matrix[k][j];
                }
                set<int> st;
                st.insert(0);
                int cursum = 0;
                for(int &pre: prefix) {
                    cursum += pre;
                    auto it = st.lower_bound(cursum - k);
                    if(it != st.end()) {
                        res = max(res, cursum - *it);
                    }
                    st.insert(cursum);
                }
            }
        }
        return res;
    }
};

