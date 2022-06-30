class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum = 0;
        for(int x: chalk) sum += x;
        k = k % sum;
        int i;
        for(i = 0; i < chalk.size() && k - chalk[i] >= 0; i++) {
            k -= chalk[i];
        }
        return i;
    }
};