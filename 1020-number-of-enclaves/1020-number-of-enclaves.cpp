class Solution {
public:
    int isBoundary(vector<vector<int>>& grid, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        if(row < 0 || col < 0 || row == m || col == n || grid[row][col] == 0) return 0;
        if(row == 0 || col == 0 || row == m - 1 || col == n - 1) return -1;
        int res = 1;
        grid[row][col] = 0;
        bool flag = false;
        int temp1 = isBoundary(grid, row - 1, col);
        if(temp1 == -1) flag = true;
        else{
            res += temp1;
        }
        int temp2 = isBoundary(grid, row + 1, col);
        if(temp2 == -1) flag = true;
        else{
            res += temp2;
        }
        int temp3 = isBoundary(grid, row, col - 1);
        if(temp3 == -1) flag = true;
        else{
            res += temp3;
        }
        int temp4 = isBoundary(grid, row, col + 1);
        if(temp4 == -1) flag = true;
        else{
            res += temp4;
        }
        return (flag)? -1: res;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                int temp = isBoundary(grid, i, j);
                if(temp != -1)
                    res += temp;
            }
        }
        return res;
    }
};