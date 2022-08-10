/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* cur, unordered_map<Node*, Node*>& mp) {
        Node* clone = new Node(cur->val);
        mp[cur] = clone;
        vector<Node*> temp;
        for(auto it: cur->neighbors) {
            if(mp.find(it) != mp.end()) {
                temp.push_back(mp[it]);
            }
            else {
                temp.push_back(dfs(it, mp));
            }
        }
        clone->neighbors = temp;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};