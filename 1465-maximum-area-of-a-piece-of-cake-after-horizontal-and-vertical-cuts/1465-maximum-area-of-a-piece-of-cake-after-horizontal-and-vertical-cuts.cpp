class Solution {
public:
    int long long md = 1000000007;
    int maxArea(int h, int w, vector<int>& hcuts, vector<int>& vcuts) {
        sort(hcuts.begin(), hcuts.end());
        sort(vcuts.begin(), vcuts.end());
        int mx = hcuts[0], my = vcuts[0];
        int n = hcuts.size(), m = vcuts.size();
        for(int i = 1; i < n; i++) {
            mx = max(mx, hcuts[i] - hcuts[i - 1]);
        }
        mx = max(mx, h - hcuts[n - 1]);
        for(int i = 1; i < m; i++) {
            my = max(my, vcuts[i] - vcuts[i - 1]);
        }
        my = max(my, w - vcuts[m - 1]);        
        return ( (mx % md) * (my % md) ) % md;
    }
};