class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            int start = n - i;
            int end = i + 1;
            int total = ceil((start * end) / 2.0);
            res += total * arr[i];
        }
        return res;
    }
};