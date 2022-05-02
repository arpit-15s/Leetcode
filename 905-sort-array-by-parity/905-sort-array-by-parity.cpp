class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int k = n - 1;
        for(int i = 0; i < k; i++){
            if(nums[i] % 2 != 0){
                swap(nums[i], nums[k]);
                k--;
                i--;
            }
        }
        return nums;
    }
};