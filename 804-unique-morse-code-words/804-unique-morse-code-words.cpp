class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> maps = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> st;
        for(string &s: words) {
            string temp = "";
            for(char &c: s) {
                temp += maps[c-'a'];
            }
            st.insert(temp);
        }
        return st.size();
    }
};