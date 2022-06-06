class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> vis;
        //mark all deadends visited
        for(int i=0; i<deadends.size(); i++){
            if(deadends[i] == "0000") return -1;
            vis.insert(deadends[i]);
        }
        if(target == "0000") return 0;
        
        //set for bfs from starting point
        unordered_set<string> start;
        //insert 0000 in start
        start.insert("0000");
        
        //another set to bfs from target
        unordered_set<string> end;
        end.insert(target);
        
        //level of bfs that will give us our answer
        int level = 0;
        
        //bfs
        while(!start.empty() and !end.empty()) {
            unordered_set<string> temp;
            for(string s: start) {
                if(end.count(s)) return level;
                if(vis.count(s)) continue;
                vis.insert(s);
                for(int i = 0; i < 4; i++) {
                    string s1 = s, s2 = s;
                    s1[i] = s[i] == '0' ? '9' : s[i] - 1;
                    s2[i] = s[i] == '9' ? '0' : s[i] + 1;
                    
                    if(!vis.count(s1)){
                        // vis.insert(s1);
                        temp.insert(s1);
                    }
                    if(!vis.count(s2)){
                        // vis.insert(s2);
                        temp.insert(s2);
                    }
                }
            }
            start = end;
            end = temp;
            level++;
        }
        
        return -1;
    }
};