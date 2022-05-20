class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> dp(m, vector<long>(n, 0));
        for(int i = m - 1; i >= 0; i--){
            if(!obstacleGrid[i][n - 1]) dp[i][n - 1] = 1;
            else break;
        }
            
        for(int j = n - 1; j >= 0; j--){
            if(!obstacleGrid[m - 1][j]) dp[m - 1][j] = 1;
            else break;
        }
        
        for(int i = m - 2; i >= 0; i--){
            for(int j = n - 2; j >= 0; j--){
                if(obstacleGrid[i][j] != 1)
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};