class Solution {
public:
    void colorFunc(vector<vector<int>>& grid, int row, int col, int color, int prevColor, vector<vector<bool>>& visited){
        int m = grid.size();
        int n = grid[0].size();
        if(row < 0 || col < 0 || row == m || col == n || visited[row][col] || (grid[row][col] != prevColor && grid[row][col] != 0)) return;
        visited[row][col] = true;
        if(grid[row][col] != 0)
            grid[row][col] = color;
        colorFunc(grid, row + 1, col, color, prevColor, visited);
        colorFunc(grid, row - 1, col, color, prevColor, visited);
        colorFunc(grid, row, col + 1, color, prevColor, visited);
        colorFunc(grid, row, col - 1, color, prevColor, visited);
        return;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        if(grid[row][col] == color) return grid;
        int m = grid.size();
        int n = grid[0].size();
        int temp = grid[row][col];
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i + 1 < m && j + 1 < n && i - 1 >= 0 && j - 1 >= 0 && grid[i][j] == temp){
                    if((grid[i - 1][j] == temp || grid[i - 1][j] == 0) && 
                      (grid[i + 1][j] == temp || grid[i + 1][j] == 0) &&
                      (grid[i][j - 1] == temp || grid[i][j - 1] == 0) &&
                      (grid[i][j + 1] == temp || grid[i][j + 1] == 0)){
                        grid[i][j] = 0;
                    }
                }
            }
        }
        // for(vector<int> i: grid){
        //     for(int j: i)
        //         cout << j << " ";
        //     cout << endl;
        // }
        colorFunc(grid, row, col, color, temp, visited);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0)
                    grid[i][j] = temp;
            }
        }
        return grid;
    }
};