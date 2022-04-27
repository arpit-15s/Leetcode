class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min = prices[0];
        int profit = 0;
        for(int i = 1; i < n; i++){
            profit = max(profit, prices[i] - min);
            if(min > prices[i])
                min = prices[i];
        }
        return profit;
    }
};