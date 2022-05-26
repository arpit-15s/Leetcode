class Solution {
public:
    void fillOranges(vector<vector<int>>& grid, vector<vector<int>>& temp_grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        temp_grid[i][j] = 2;
        if(i - 1 >= 0 && grid[i - 1][j] == 1) temp_grid[i - 1][j] = 2;
        if(i + 1 < m && grid[i + 1][j] == 1) temp_grid[i + 1][j] = 2;
        if(j - 1 >= 0 && grid[i][j - 1] == 1) temp_grid[i][j - 1] = 2;
        if(j + 1 < n && grid[i][j + 1] == 1) temp_grid[i][j + 1] = 2;
        return;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        while(true){
            vector<vector<int>> temp_grid(m, vector<int>(n, 0));
            bool fresh = false, rotten = false;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 2){
                        rotten = true;
                        fillOranges(grid, temp_grid, i, j);
                    }
                    else if(grid[i][j] == 1){
                        fresh = true;
                        if(temp_grid[i][j] != 2)
                            temp_grid[i][j] = 1;
                    }
                        
                }
            }
            // for(vector<int> i: temp_grid){
            //     for(int j: i)
            //         cout << j << " ";
            //     cout << endl;
            // }
            // cout << endl;
            if(!fresh) return count;
            if(!rotten | temp_grid == grid) return -1;
            count++;
            grid = temp_grid;
        }
        return 0;
    }
};