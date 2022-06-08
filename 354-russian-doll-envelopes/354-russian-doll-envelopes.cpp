class Solution {
public:
    static bool cmp(vector<int>& e1, vector<int>& e2){
        if(e1[0] == e2[0]) return e2[1] < e1[1];
        else return e1[0] < e2[0];
    }
    int lowerBound(vector<int>& temp, int x) {
        int left = 0, right = temp.size() - 1;
        while(left < right) {
            int mid  = left + (right - left) / 2;
            if(temp[mid] < x) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> temp;
        for(int i = 0; i < envelopes.size(); i++) {
            if(temp.size() == 0 || temp.back() < envelopes[i][1]) temp.push_back(envelopes[i][1]);
            else{
                int idx = lowerBound(temp, envelopes[i][1]);
                temp[idx] = envelopes[i][1];
            }
        }
        return temp.size();
    }
};