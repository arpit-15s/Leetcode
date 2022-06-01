class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int min_amount = prices[0];
        for(int i = 1; i < n; i++){
            profit = max(prices[i] - min_amount, profit);
            min_amount = min(min_amount, prices[i]);
        }
        return profit;
    }
};