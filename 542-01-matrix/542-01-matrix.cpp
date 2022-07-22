class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, m * n));
        queue<pair<int, int>> q1, q2;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q1.push(make_pair(i, j));
                    dp[i][j] = 0;
                }
            }
        }
        int level = 1;
        while(!q1.empty()){
            while(!q1.empty()){
                pair<int, int> pos = q1.front();
                q1.pop();
                if(pos.first - 1 >= 0 && dp[pos.first - 1][pos.second] == m * n){
                    dp[pos.first - 1][pos.second] = level;
                    q2.push(make_pair(pos.first - 1, pos.second));
                }
                if(pos.first + 1 < m && dp[pos.first + 1][pos.second] == m * n){
                    dp[pos.first + 1][pos.second] = level;
                    q2.push(make_pair(pos.first + 1, pos.second));
                }
                if(pos.second - 1 >= 0 && dp[pos.first][pos.second - 1] == m * n){
                    dp[pos.first][pos.second - 1] = level;
                    q2.push(make_pair(pos.first, pos.second - 1));
                }
                if(pos.second + 1 < n && dp[pos.first][pos.second + 1] == m * n){
                    dp[pos.first][pos.second + 1] = level;
                    q2.push(make_pair(pos.first, pos.second + 1));
                }   
            }
            q1 = q2;
            while(!q2.empty()) q2.pop();
            level++;
        }
        return dp;
    }
};