class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        int breakpoint = -1;
        while(i != 0){
            if(nums[i] > nums[i - 1]){
                breakpoint = i - 1;
                break;
            }
            i--;
        }
        if(breakpoint == - 1){
            reverse(nums.begin(), nums.end());
            return;
        }
        int min_val = i;
        i = n - 1;
        while(i != breakpoint){
            if(nums[i] > nums[breakpoint] && nums[i] <= nums[min_val]){
                min_val = i;
                break;
            }
            i--;
        }
        swap(nums[breakpoint], nums[min_val]);
        reverse(nums.begin() + breakpoint + 1, nums.end());
        return;
    }
};
// 1 -> 4 -> 6 -> 3 -> 2 -> 1
// 1 -> 6 -> 4 -> 3 -> 2 -> 1
// 2 -> 1 -> 1 -> 3 -> 4 -> 6