class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1);
        //first travel from left and check the increasing seq and keep adding one
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1])
                candy[i] = candy[i - 1] + 1;
        }
        //then travel fromm right and find the decreasing seq and update to max of prev stored value and cur + 1
        for(int i = n - 1; i > 0; i--) {
            if(ratings[i] < ratings[i - 1])
                candy[i - 1] = max(candy[i - 1], candy[i] + 1);
        }
        //sum of all the candies
        int res = 0;
        for(int x: candy){
            res += x;
        }
        return res;
    }
};