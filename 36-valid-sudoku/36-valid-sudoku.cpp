class Solution {
public:
    bool isValidboard(vector<vector<char>>& board, int idx, int jdx){
        char num = board[idx][jdx];
        for(int i = 0; i < 9; i++){
            if(i != idx && board[i][jdx] == num) return false;
        }
        for(int j = 0; j < 9; j++){
            if(j != jdx && board[idx][j] == num) return false;
        }
        
        int starti = (idx / 3) * 3;
        int startj = (jdx / 3) * 3;
        // cout << starti << " " << startj << endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if((starti + i) != idx && (startj + j) != jdx){
                    if(board[starti + i][startj + j] == num) return false;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.')
                    if(!isValidboard(board, i, j)) return false;
            }
        }
        return true;
    }
};