class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n - 1] = true;
        for(int i = n - 1; i >= 0; i--){
            int j = nums[i];
            while(j > 0){
                if(i + j < n && dp[i + j] == true){
                    dp[i] = true;
                    break;
                }
                j--;
            }
        }
        return dp[0];
    }
};