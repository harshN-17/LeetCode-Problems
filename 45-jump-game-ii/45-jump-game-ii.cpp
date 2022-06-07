class Solution {
public:
    
    int jump(vector<int>& nums) {
        int curjmp = 0, maxjmp = 0, jumps = 0;
        for(int i = 0; i < nums.size()-1 ; i++) {
            maxjmp = max(maxjmp, i + nums[i]);
            if(curjmp == i) {
                curjmp = maxjmp;
                jumps++;
            }
        }
        return jumps;
    }
};