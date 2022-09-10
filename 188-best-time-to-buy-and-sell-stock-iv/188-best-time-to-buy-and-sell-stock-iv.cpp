class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for(int i = 1; i <= k; i++){
            for(int j = 1; j < n; j++){
                int max_profit = 0;
                for(int it = j - 1; it >= 0; it--){
                    max_profit = max(max_profit, prices[j] - prices[it] + dp[i - 1][it]);
                }
                dp[i][j] = max(dp[i][j - 1], max_profit);
            }
        }
        return dp[k][n - 1];
    }
};