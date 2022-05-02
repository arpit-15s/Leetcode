class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<long> dp(n, INT_MAX);
        dp[n - 1] = 0;
        for(int i = n - 1; i >= 0; i--){
            int j = nums[i];
            while(j > 0){
                if(i + j < n)
                    dp[i] = min(dp[i], dp[i + j] + 1);
                j--;
            }
        }
        return dp[0];
    }
};