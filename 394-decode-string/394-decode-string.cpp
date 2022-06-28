class Solution {
public:
    string solve(string s, int &i) {
        string res = "";
        
        for(; i < s.size(); i++) {
            if(isdigit(s[i])) {
                int x = 0;
                //calculate the integer number
                while(i < s.size() && isdigit(s[i])) {
                    x = x*10 + s[i] - '0';    
                    i++;
                }
                // now s[i] = '['
                // so recursively find the sub-solution of inner brackets for next index
                i++;
                string t = solve(s, i);        
                //store t in res x times;
                while(x--) {
                    res += t;
                }
            }
            else if(s[i] == ']')
                return res;
            else res += s[i];       
        }        
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }
};