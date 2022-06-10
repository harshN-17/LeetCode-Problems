class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n = s.size(), count = 0;
        int i = 0, j = 0, mx = 0;
        while(j<n){
            if(i==j) count=0;
            if(mp.find(s[j])==mp.end()){
                mp[s[j]]=1;
                count++;
                j++;
            }
            else{
                count--;
                mp.erase(s[i++]);
            }
            mx = max(mx,count);
        }
       
        return mx;
    }
};