class Solution {
public:
    bool isSafe(vector<string> board, int row, int col, int n){
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q') return false;
        }
        int i=row, j=col;
        while(i>=0 and j>=0){
            if(board[i][j]=='Q') return false;
            i--; j--;
        }
        
        i=row,j=col;
        while(i>=0 and j<n){
            if(board[i][j]=='Q') return false;
            i--; j++;
        }
        return true;
    }
    void solve(vector<vector<string>> &res, vector<string> board, int n, int row){
        if(row==n){
            res.push_back(board);
        }
        for(int col=0;col<n;col++){
            if(isSafe(board,row,col,n)){
                board[row][col] = 'Q';
                solve(res,board,n,row+1);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) board[i] = s;
        solve(res,board,n,0);
        return res;
    }
};