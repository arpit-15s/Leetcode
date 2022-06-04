class Solution {
public:
    bool isSafe(vector<vector<bool>>& chess, int row, int col){
    for(int i = row - 1; i >= 0; i--){
        if(chess[i][col] == true) return false;
    }
    
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
        if(chess[i][j] == true) return false;
    }
    
    for(int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--, j++){
        if(chess[i][j] == true) return false;
    }
    return true;
}

void nqueens(vector<vector<bool>>& chess, int row, vector<string>& qsf, vector<vector<string>>& res, string s){
    if(row == chess.size()){
        res.push_back(qsf);
        return;
    }
    for(int col = 0; col < chess[row].size(); col++){
        if(isSafe(chess, row, col)){
            chess[row][col] = true;
            s[col] = 'Q';
            qsf.push_back(s);
            s[col] = '.';
            nqueens(chess, row + 1, qsf, res, s);
            qsf.pop_back();
            chess[row][col] = false;
        }
    }
}
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> chess(n, vector<bool> (n ,false));
        vector<vector<string>> res;
        vector<string> v;
        string s;
        for(int i =0; i < n; i++){
            s.insert(s.begin(), '.');
        }
        nqueens(chess, 0, v, res, s);
        return res;
    }
};