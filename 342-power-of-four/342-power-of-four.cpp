class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1 || n == 0) return n;
        if(n % 4 != 0) return false;
        if(!isPowerOfFour(n / 4)) return false;
        return true;
    }
};