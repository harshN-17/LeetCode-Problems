class Solution {
public:
    int count(int n) {
        long long res = 0;
        while(n) {
            res += pow(10, n % 10);
            n /= 10;
        }
        return res;
    }
    bool reorderedPowerOf2(int n) {
        // if((n & (n - 1)) == 0) return true;
        int digitsum = count(n);
        for(int i = 0; i < 32; i++) {
            if(count(1 << i) == digitsum) return true;
        }
        return false;
    }
};