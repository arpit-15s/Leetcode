class Solution {
public:
    int dp[20];
    int numTrees(int n) {
        if(n <= 1)  return 1;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int left = (dp[i - 1] != 0)? dp[i - 1]: numTrees(i - 1);
            int right = (dp[n - i] != 0)? dp[n - i]: numTrees(n - i);
            ans += (left * right);
        }
        dp[n] = ans;
        return ans;
    }
};