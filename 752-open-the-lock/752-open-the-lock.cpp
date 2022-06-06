class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> vis;
        for(int i=0; i<deadends.size(); i++){
            if(deadends[i] == "0000") return -1;
            vis.insert(deadends[i]);
        }
        if(target == "0000") return 0;
        queue<string> q;
        q.push("0000");
        vis.insert("0000");
        
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                string cur = q.front();
                q.pop();
                if(cur == target) return level;
                for(int i = 0; i < 4; i++) {
                    string s1 = cur, s2 = cur;
                    s1[i] = s1[i] == '0' ? '9' : s1[i]-1;
                    s2[i] = s2[i] == '9' ? '0' : s2[i]+1;
                    if(!vis.count(s1)) {
                        vis.insert(s1);
                        q.push(s1);
                    }
                    if(!vis.count(s2)) {
                        vis.insert(s2);
                        q.push(s2);
                    }                    
                }
            }
            level++;
        }
        return -1;
    }
};