class Solution {
public:
    void traverse(vector<vector<char>>& grid, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        if(row < 0 || col < 0 || row == m || col == n || grid[row][col] == '0') return;
        grid[row][col] = '0';
        traverse(grid, row - 1, col);
        traverse(grid, row + 1, col);
        traverse(grid, row, col - 1);
        traverse(grid, row, col + 1);
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    count++;
                    traverse(grid, i, j);
                }
            }
        }
        return count;
    }
};