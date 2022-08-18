class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto &x: arr) {
            mp[x]++;
        }
        priority_queue<int> pq;
        for(auto &it: mp) {
            pq.push(it.second);
        }
        int sum = 0, cnt = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
            cnt++;
            if(sum >= arr.size() / 2) return cnt;
        }
        return cnt;
    }
};