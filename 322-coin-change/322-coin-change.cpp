class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            long minVal = INT_MAX;
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0)
                    minVal = min(minVal, 1 + dp[i - coins[j]]);
            }
            dp[i] = minVal;
        }
        if(dp[amount] != INT_MAX)
        return dp[amount];
        else return -1;
    }
};