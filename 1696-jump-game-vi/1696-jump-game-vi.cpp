class Solution {
public:
    int getmax(priority_queue<pair<int, int>>& pq, int i, int k){
        while(!pq.empty() && pq.top().second > i + k) pq.pop();
        return pq.top().first;
    }
    
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> dp(n, 0);
        dp[n - 1] = nums[n - 1];
        int max = INT_MIN;
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(nums[n - 1], n - 1));
        for(int i = n - 2; i >= 0; i--){
            dp[i] = nums[i] + getmax(pq, i, k);
            pq.push(make_pair(dp[i], i));
        }
        return dp[0];
    }
};