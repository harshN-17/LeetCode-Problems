class Solution {
public:
    int numberOfSteps(int num) {
        if(!num) return 0;
        int cnt=0;
        while(num){
            cnt += num&1 ? 2: 1;
            num = num >> 1;
        }
        return cnt-1;
    }
};