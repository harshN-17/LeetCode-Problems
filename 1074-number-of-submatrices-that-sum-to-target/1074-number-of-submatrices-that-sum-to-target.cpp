class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int res = 0;
        int n = matrix.size(), m = matrix[0].size();
        //row-wise prefix sum
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < m; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        
        //outer loop for every column
        for(int i = 0; i < m; i++) {
            //2nd nested loop for every number of next columns
            for(int j = i; j < m; j++) {
                int cursum = 0;
                unordered_map<int, int> mp;
                mp[0]++;
                //3rd nested loop for the row cells
                for(int k = 0; k < n; k++) {
                    cursum += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    if(mp.find(cursum - target) != mp.end()) res += mp[cursum - target];
                    mp[cursum]++;
                }
            }
        }
        return res;
    }
};