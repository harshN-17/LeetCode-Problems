class Solution {
public:
    int countNode(vector<int> &l, vector<int> &r, int root) {
        if(root == -1) return 0;
        return 1 + countNode(l, r, l[root]) + countNode(l , r, r[root]);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>> graph(n);
        vector<int> indeg(n, 0);
        int root = -1;
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1 && ++indeg[leftChild[i]] > 1) return false;
            if(rightChild[i] != -1 && ++indeg[rightChild[i]] > 1) return false;            
        }
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) {
                if(root == -1) root = i;
                else return false;
            }
        }
        return countNode(leftChild, rightChild, root) == n;
    }
};