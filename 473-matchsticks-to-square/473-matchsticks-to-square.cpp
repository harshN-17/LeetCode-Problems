# define ll long long
class Solution {
public:
    bool solve(vector<int>& sticks, ll& side, vector<ll> sums, int index) {
        //base case
        if(index == sticks.size()) {
            //if all the sides are same
            for(int i = 1; i < 4; i++) {
                if(sums[i] != sums[i - 1]) return false; 
            }
            return true;
        }
        int cur = sticks[index];
        for(int i = 0; i < 4; i++) {
            // add the current stick to this side and recurse
            // if the sum is <= possible side of this square
            if(sums[i] + cur > side) continue;
            int j = i;
            while(--j >= 0) {
                if(sums[i] == sums[j]) break;
            }
            if(j != -1) continue;
            sums[i] += cur;
            if(solve(sticks, side, sums, index + 1)) return true;
            //backtrack the sum of this side
            sums[i] -= cur;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        ll side = 0;
        for(int x: matchsticks) side += x;
        if(side % 4 != 0) return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        side /= 4;
        for(int x: matchsticks) if(x > side) return false;
        return solve(matchsticks, side, {0,0,0,0}, 0);
    }
};

