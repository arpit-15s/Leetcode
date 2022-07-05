class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1])
                dp[i] = dp[i - 1] + 1;
        }
        int res = 0;
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                dp[i] = max(dp[i], dp[i + 1] + 1);
            }
            res += dp[i];
        }
        for(int i: dp)
            cout << i << " ";
        cout << endl;
        return res + dp[n - 1];
    }
};