class Solution {
public:
    int count(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] <= target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int res, n = mat.size();
        int low = mat[0][0], high = mat[n - 1][n - 1];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                cnt += count(mat[i], mid);
            }
            if(cnt < k ) {
                low = mid + 1;
            }
            else {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }
};