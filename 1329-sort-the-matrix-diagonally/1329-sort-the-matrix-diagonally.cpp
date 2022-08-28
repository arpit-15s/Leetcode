class Solution {
public:
    void sortDiagonal(vector<vector<int>>& mat, int rowIndex, int colIndex){
        int m = mat.size();
        int n = mat[0].size();
        int i = rowIndex, j = colIndex;
            vector<int> temp;
            while(i < m && j < n){
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(), temp.end());
            i = rowIndex, j = colIndex;
            for(int num: temp){
                mat[i][j] = num;
                i++;
                j++;
            }
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int row = m - 1;
        while(row != -1){
            sortDiagonal(mat, row, 0);
            row--;
        }
        int col = 1;
        while(col != n){
            sortDiagonal(mat, 0, col);
            col++;
        }
        return mat;
    }
};