class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, bool>> dp(n, {1, 0});
        int res = 1;
        for(int i = 1; i < n; i++){
            // bool small = false, large = false;
            
            for(int j = i - 1; j  >= 0; j--){
                if(nums[i] != nums[j]){
                    if(j == 0 && dp[j].first == dp[i].first){
                        if(nums[j] > nums[i]){
                            dp[i] = make_pair(2, 0);
                        }
                        else if(nums[j] < nums[i]){
                            dp[i] = make_pair(2, 1);
                        }
                    }
                    else if(dp[j].first > dp[i].first){
                        if(nums[j] > nums[i] && dp[j].second == 1){
                            dp[i] = make_pair(dp[j].first + 1, !dp[j].second);
                        }
                        else if(nums[j] < nums[i] && dp[j].second == 0){
                            dp[i] = make_pair(dp[j].first + 1, !dp[j].second);
                        }
                    }
                }
            }
            res = max(res, dp[i].first);
        }
        // for(pair<int, bool> i: dp){
        //     cout << i.first << " " << i.second << " -> ";
        // }
        // cout << endl;
        return res;
    }
};