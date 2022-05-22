class Solution {
public:
    int find(string s, int n, int l, int r){
        while(l>=0 and r<n and s[l]==s[r]){
            l--; r++;
        }
        return r-l-1;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            int l1 = find(s,n,i,i);
            int l2 = find(s,n,i,i+1);
            cnt += (l1+l2)/2 + 1;
        }
        return cnt;
    }
};