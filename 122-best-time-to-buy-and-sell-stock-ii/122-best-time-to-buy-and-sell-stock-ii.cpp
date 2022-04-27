class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        bool holding = false;
        int brought = 0;
        for(int i = 0; i < n - 1; i++){
            if(prices[i] < prices[i + 1] && !holding){
                brought = prices[i];
                holding = true;
            }
            else if(prices[i] > prices[i + 1] && holding){
                profit += prices[i] - brought;
                holding = false;
            }
        }
        if(holding && prices[n - 1] > brought){
            profit += prices[n - 1] - brought;
        }
        return profit;
    }
};