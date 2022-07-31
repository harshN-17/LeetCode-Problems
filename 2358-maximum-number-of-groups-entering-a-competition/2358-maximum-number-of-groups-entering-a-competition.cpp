class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int count = 0, sum = 0;
        while(sum < n) {
            count++;
            sum = (count * (count + 1) / 2);
        }
        return sum == n ? count : count - 1;
    }
};