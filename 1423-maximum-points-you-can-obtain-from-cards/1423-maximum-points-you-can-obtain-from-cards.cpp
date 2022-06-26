class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int cursum = 0;
        int n = cardPoints.size();
        long sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        for(int i = 0; i < n - k; i++) {
            cursum += cardPoints[i];
        }
        int minsum = cursum;
        for(int i = n - k; i < n; i++) {
            cursum = cursum + cardPoints[i] - cardPoints[i - n + k];
            minsum = min(minsum, cursum);
        }
        return sum - minsum;
    }
};