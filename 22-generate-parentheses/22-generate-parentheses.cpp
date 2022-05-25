class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        // to generate all possible strings with n numbers of '(' and ')'
        generateAll(n, res, "", 0, 0);
        return res;
    }
    
    void generateAll(int n, vector<string>& res, string s, int a, int b){
        //base case - when the total length becomes 2*n
        //check if the parentheses are balanced and add it to the res vector
        if(s.size()==2*n){
            //if(isValid(s))
            res.push_back(s);
            return;
        }
        
        //recusrion for '(' until its length becomes n
        if(a<n)
            generateAll(n, res, s+'(', a+1, b);
        
        //recusrion for ')' until its length becomes n        
        if(b<a)
            generateAll(n, res, s+')', a, b+1);   
    }
    
    bool isValid(string s){
        stack<char> st;
        for(char c: s){
            switch(c){
                case '(' : 
                    st.push(c);
                    break;
                case ')' : 
                    if(st.empty()) return false;
                    else st.pop();
            }
        }
        return st.empty();
    }
};