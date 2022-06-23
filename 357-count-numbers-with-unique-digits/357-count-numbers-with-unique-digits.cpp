class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;
        int unique = 9, next = 9, res = 10;
        while(n-- > 1 && next) {
            unique *= next;
            next--;
            res += unique;
        }
        return res;
    }
};