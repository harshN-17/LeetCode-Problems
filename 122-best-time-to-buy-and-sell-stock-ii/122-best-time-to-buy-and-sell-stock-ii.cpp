class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,n=prices.size()-1;
        for(int i=0; i<n; ++i){
            if(prices[i]<prices[i+1])
                profit = profit+prices[i+1]-prices[i];
        }
        
        return profit;
    }
};