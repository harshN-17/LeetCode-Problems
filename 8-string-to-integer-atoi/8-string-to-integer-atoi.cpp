class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, i = 0;
        long long total = 0;
        //initial empty spaces
        while(i < s.size() && s[i] == ' ') i++;
        //if the string terminates
        if(i >= s.size()) return 0;
        //check for +/- sign
        if(s[i] == '-') {
            i++;
            sign = -1;
        }
        else if(s[i] == '+') {
            i++;
            sign = 1;
        }
        
        //check for consecutive digits
        while(i < s.size() && isdigit(s[i])) {
            total = total * 10 + (s[i] - '0');
            if(sign * total >= INT_MAX) return INT_MAX;
            else if(sign * total <= INT_MIN) return INT_MIN;
            i++;
        }
        return sign * total;
    }
};