# define MOD 1000000007
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, long> mp;
        int n = arr.size(), count;
        int res = 0;
        mp[arr[0]] = 1;
        for(int i = 1; i < n; i++) {
            count = 1;
            for(auto it: mp) {
                if(arr[i] % it.first == 0 && mp.find(arr[i] / it.first) != mp.end()) {
                    count = (count + (mp[it.first] * mp[arr[i] / it.first]) % MOD) % MOD;
                }
            }
            mp[arr[i]] = count % MOD;
        }
        for(auto it: mp) {
            res = (res % MOD + it.second % MOD) % MOD;
        }
        return res;
    }
};