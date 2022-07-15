class Solution {
public:
    void util(vector<vector<int>>& grid, int row, int col, int& count){
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || grid[row][col] == 0) return;
        count++;
        grid[row][col] = 0;
        util(grid, row + 1, col, count);
        util(grid, row - 1, col, count);
        util(grid, row, col + 1, count);
        util(grid, row, col - 1, count);
        return;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_count = 0;
        for(int i =0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                int count = 0;
                util(grid, i, j, count);
                max_count = max(max_count, count);
            }
        }
        return max_count;
    }
};