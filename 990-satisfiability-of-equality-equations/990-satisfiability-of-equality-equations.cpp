class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void connect(int x, int y) {
        int px = find(x), py = find(y);
        if(px != py) {
            parent[py] = px;
        }
    }
    
    bool isConnect(int u, int v) {
        return find(u) == find(v);
    }
    
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        int n = equations.size();
        for(int i = 0; i < 26; i++) {
            parent[i] = i;
        }
    
        for(string e: equations) {
            if(e[1] == '=') {
                connect(e[0] - 'a', e[3] - 'a');
            }
        }
        
        for(string e: equations) {
            if(e[1] == '!') {
                if(isConnect(e[0] - 'a', e[3] - 'a')) return false;
            }
        }
        return true;
    }
};