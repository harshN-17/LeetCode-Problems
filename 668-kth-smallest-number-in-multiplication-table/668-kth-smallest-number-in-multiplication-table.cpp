class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        int res = 0;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for(int i = 1; i <= m; i++) {
                // int x = mid % i == 0 ? 0 : 1;
                cnt += (min(n , mid / i));
            }
            // cout<<mid << ' '<<cnt<<endl;
            if(cnt < k) {
                left = mid + 1;
            }
            else {
                res=mid;
                right = mid - 1;
            }
        }
        return res;
    }
};