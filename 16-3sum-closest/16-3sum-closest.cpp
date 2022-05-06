class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int res = 0;
        for(int i = 0; i < n - 2; i++){
            int j = i + 1, k = n - 1;
            while(j != k){
                int temp_sum = nums[i] + nums[j] + nums[k];
                if(abs(target - temp_sum) < diff){
                    res = temp_sum;
                    diff = abs(target - temp_sum);
                }
                if(temp_sum > target) k--;
                else j++;
            }
        }
        return res;
    }
};