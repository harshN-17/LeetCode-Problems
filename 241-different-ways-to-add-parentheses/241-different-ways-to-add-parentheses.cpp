class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> res;
        for(int i = 0; i < exp.size(); i++) {
            if(isdigit(exp[i])) continue;
            char sign = exp[i];
            string s1 = exp.substr(0,i);
            string s2 = exp.substr(i + 1);
            vector<int> r1 = diffWaysToCompute(s1);
            vector<int> r2 = diffWaysToCompute(s2);
            for(int x: r1) {
                for(int y: r2) {
                    switch(sign) {
                        case '+' : res.push_back(x+y);
                            break;
                        case '-' : res.push_back(x-y);
                            break;
                        case '*' : res.push_back(x*y);
                    }
                }
            }
        }
        
        if(res.size() == 0)  {
            int num = 0, n = 0;
            while(n < exp.size()) {
                num = num*10 + exp[n++] - '0';
            }
            res.push_back(num);
        }
        return res;
    }
};