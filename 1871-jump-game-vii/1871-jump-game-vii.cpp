class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<bool> dp(n, false);
        int pre = 0;
        dp[0] = true;
        for(int i = 1; i < n; i++){
            if(i >= minJump){
                pre += dp[i - minJump];
            }
            if(i > maxJump){
                pre -= dp[i - maxJump - 1];
            }
            dp[i] = (pre > 0) && (s[i] == '0');
        }
        return dp[n - 1];
    }
};