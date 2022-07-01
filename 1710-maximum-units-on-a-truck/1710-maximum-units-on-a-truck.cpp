class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res = 0;
        sort(boxTypes.begin(), boxTypes.end(), cmp);    
        for(auto box: boxTypes) {
            int x = min(box[0], truckSize);
            res += x * box[1];
            truckSize -= x;
            if(truckSize == 0) break;
        }
        return res;
    }
};