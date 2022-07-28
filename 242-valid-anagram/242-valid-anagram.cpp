class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        for(int x:s){
            m[x]++;
        }
        for(int x:t){
            m[x]--;
        }
        
        for(auto it:m)
            if(it.second!=0)
                return false;
                
        return true;
    }
};