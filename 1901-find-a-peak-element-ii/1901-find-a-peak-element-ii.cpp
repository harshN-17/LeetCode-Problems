class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int startCol = 0, endCol = m - 1;
        while(startCol <= endCol) {
            int midCol = startCol + (endCol - startCol) / 2;
            int maxRow = 0;
            for(int i = 1; i < n; i++){
                if(mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }    
            }
            int left = midCol > 0 ? mat[maxRow][midCol - 1] : -1;
            int right = midCol < m - 1 ? mat[maxRow][midCol + 1] : -1;
            
            if(mat[maxRow][midCol] > left && mat[maxRow][midCol] > right) return {maxRow, midCol};
            else if(mat[maxRow][midCol] < right) startCol = midCol + 1;
            else endCol = midCol - 1;
        }
        return {-1, -1};
    }
};