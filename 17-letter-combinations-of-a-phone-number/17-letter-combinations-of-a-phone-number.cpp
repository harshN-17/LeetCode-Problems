class Solution {
public:
    
    void solve(string digits, vector<string> &mapping, string out, vector<string> &res, int index){
        if(index == digits.size()){
            res.push_back(out);
            return;
        }
        
        int d = digits[index]-'0';
        string s = mapping[d];
        for(int i=0;i<s.size();i++){
            out += s[i];
            solve(digits,mapping,out,res,index+1);
            out.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        if(digits.size()==0) return res;
        string out;
        solve(digits,mapping,out,res,0);
        return res;
    }
};