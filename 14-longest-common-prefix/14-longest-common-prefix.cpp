class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string s = strs[0];
        for(int i=1; i<n; i++){
            int j=0;
            for(int k=0;k<s.size() and k<strs[i].size();k++){
                if(s[k]!=strs[i][k]) break;
                j++;
            }
            
            s = s.substr(0,j);
        }
        return s;
    }
};