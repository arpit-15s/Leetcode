class Solution {
public:
    bool fillDist(vector<vector<int>>& grid, int num){
        int n = grid.size();
        bool res = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == n * n) res = true;
                if(num == grid[i][j]){
                    if(i - 1 >= 0) grid[i - 1][j] = min(grid[i - 1][j], num + 1);
                    if(i + 1 < n) grid[i + 1][j] = min(grid[i + 1][j], num + 1);
                    if(j - 1 >= 0) grid[i][j - 1] = min(grid[i][j - 1], num + 1);
                    if(j + 1 < n) grid[i][j + 1] = min(grid[i][j + 1], num + 1);
                }
            }
        }
        return res;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int one = false, zero = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    zero = true;
                    grid[i][j] = n * n;
                }else{
                    one = true;
                    grid[i][j] = 0;
                }
            }
        }
        if(!one || !zero) return -1;
        int dist = 0;
        bool res = true;
        while(res){
            res = fillDist(grid, dist);
            dist++;
        }
        int max_ele = 0;
        for(vector<int> i: grid)
            max_ele = max(max_ele, *max_element(i.begin(), i.end()));
        return max_ele;
    }
};