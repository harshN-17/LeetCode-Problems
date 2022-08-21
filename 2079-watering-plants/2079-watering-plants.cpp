class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size(), i = 0, res = 0, sum = capacity;
        while(i < n) {
            if(sum - plants[i] >= 0) {
                sum -= plants[i];
                res++;
            }
            else {
                sum = capacity - plants[i];
                res += (2 * i) + 1;
            }
            i++;
        }
        return res;
    }
};