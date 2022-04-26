class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = n - 1; i > 0; i--){
            if(nums[i] > nums[i - 1]){
                int min = i;
                for(int j = n - 1; j >= i; j--){
                    if(nums[min] > nums[j] && nums[j] > nums[i - 1])
                        min = j;
                }
                swap(nums[min], nums[i - 1]);
                sort(nums.begin() + i, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};