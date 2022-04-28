class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> profit(n, 0);
        int max_profit = 0;
        int min_price = prices[0];
        for(int i = 1; i < n; i++){
            if(min_price > prices[i]){
                min_price = prices[i];
            }
            max_profit = max(max_profit, prices[i] - min_price);
            profit[i] = max_profit;
        }
        int max_price = prices[n - 1];
        max_profit = 0;
        for(int i = n - 2; i >= 0; i--){
            if(max_price < prices[i]){
                max_price = prices[i];
            }
            max_profit = max(max_profit, max_price - prices[i]);
            profit[i] += max_profit;
        }
        return *max_element(profit.begin(), profit.end());
    }
};