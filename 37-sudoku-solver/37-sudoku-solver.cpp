class Solution {
public:
    bool isSafe(vector<vector<char>> &board, int r, int c, char digit){
        int j = (r/3)*3, k = (c/3)*3;
        for(int i=0; i<9; i++){
            //if the number is presesnt in the same row    
            if(board[r][i]==digit) return false;
            
            //if the number is presesnt in the same column            
            if(board[i][c]==digit) return false;
            
            //if the number is presesnt in the same box
            if(board[j+(i/3)][k+(i%3)] == digit) return false;
        }
        return true;
    }
    
    bool helper(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(isSafe(board,i,j,k)){
                            board[i][j]=k;
                            if(helper(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
        return;
    }
};