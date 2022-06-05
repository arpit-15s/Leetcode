class Solution {
public:
    bool isValid(vector<vector<bool>>& board, int row, int col){
        for(int i = 0; i < row; i++){
            if(board[i][col] == true) return false;        
        }
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == true) return false;
        }
        for(int i = row, j = col; i >= 0 && j < board.size(); i--, j++){
            if(board[i][j] == true) return false;
        }
        return true;
    }
    
    void nQueens(int row, vector<vector<bool>>& board, int& count){
        if(row == board.size()){
            count++;
            return;
        }
        for(int i =0; i < board.size(); i++){
            if(isValid(board, row, i)){
                board[row][i] = true;
                nQueens(row + 1, board, count);
                board[row][i] = false;
            }
        }
        return;
    }
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        int count = 0;
        nQueens(0, board, count);
        return count;
    }
};