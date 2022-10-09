class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_product = nums[0];
        int min_pr = nums[0], max_pr = nums[0];
        for(int it = 1; it != n; it++){
            int i= nums[it];
            int temp = min_pr;
            min_pr = min(min_pr * i, min(max_pr * i, i));
            max_pr =max(max_pr * i, max(temp * i, i));
            max_product = max(max_pr, max_product);
        }
        return max_product;
    }
};