class Solution {
public:
    int findLength(string s, int st, int en){
        int n=s.size();
        while(st >= 0 and en < n and s[st]==s[en]){
            st--;
            en++;
        }
        return en-st-1;
    }
    
    string longestPalindrome(string s) {
        int n = s.size(), ans=0, st=0,en=0;
        for(int i=0; i<n; i++){
            int l1 = findLength(s,i,i);
            int l2 = findLength(s,i,i+1);
            ans = max(l1,l2);
            if(ans > en-st){
                st = i-(ans-1)/2;
                en = i+ans/2;
            }
        }
        return s.substr(st, en-st+1);
    }
};