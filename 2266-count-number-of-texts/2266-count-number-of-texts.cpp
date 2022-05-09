class Solution {
public:
    int countTexts(string pressedKeys) {
        int mod = 1000000007;
        int n = pressedKeys.length() + 1;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            dp[i] = (dp[i - 1]) % mod;
            if(i >= 2 && pressedKeys[i - 1] == pressedKeys[i - 2]){
                dp[i] = (dp[i] + dp[i - 2]) % mod;
                if(i >= 3 && pressedKeys[i - 1] == pressedKeys[i - 3]){
                        dp[i] = (dp[i] + dp[i - 3]) % mod;
                    if(i >= 4 && (pressedKeys[i - 1] == pressedKeys[i - 4]) && (pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9'))
                        dp[i] = (dp[i] + dp[i - 4]) %mod;
                }
            }
        }
        return dp[n - 1];
    }
};