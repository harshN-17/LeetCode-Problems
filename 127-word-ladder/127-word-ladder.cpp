class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_set<string> vis;
        vis.insert(beginWord);
        queue<string> q;
        q.push(beginWord);
        int level=0;
        while(!q.empty()) {
            int size = q.size();
            level++;
            while(size--) {
                string cur = q.front(); 
                q.pop();
                if(cur == endWord) return level;
                for(int i=0; i<cur.size(); i++) {
                    for(int j=0; j<26; j++) {
                        char c = cur[i];
                        cur[i] = 'a' + j;
                        if(dict.count(cur) and !vis.count(cur)){
                            vis.insert(cur);
                            q.push(cur);
                        }
                        cur[i] = c;
                    }
                }
            }
        }
        return 0;
    }
};