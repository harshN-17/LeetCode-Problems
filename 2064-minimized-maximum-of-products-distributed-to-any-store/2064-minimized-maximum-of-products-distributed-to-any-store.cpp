class Solution {
public:
    bool isValid(vector<int> q, int mid, int n) {
        int br = 0;
        int i=0;
        while( i < q.size()) {
            q[i] -= mid;
            if(q[i] <= 0) {
                i++;
            }
            br++;
        }
        // cout<<br<<endl;
        return br <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long left = 0, right = 0;
        for(long long x: quantities) {
            right = max(right, x);
            left += x;
        }
        left /= n;
        if(left == 0) return 1;
        while(left < right) {
            long long mid = left + (right - left) / 2;
            if(isValid(quantities,mid,n)) {
                right = mid;
            }
            else left = mid + 1;
            // cout<<left<<' '<<right<<' '<<mid<<endl;
        }
        return left;
    }
};