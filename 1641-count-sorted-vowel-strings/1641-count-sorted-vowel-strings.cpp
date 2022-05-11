class Solution {
public:
    int countVowelStrings(int n) {
        if(n == 1) return 5;
        vector<vector<int>> dp(5, vector<int>(n, 1));
        int sum = 0;
        for(int j = 1; j < n; j++){
            sum = 1;
            for(int i = 1; i < 5; i++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                sum += dp[i][j];
            }
        }
        return sum;
    }
};