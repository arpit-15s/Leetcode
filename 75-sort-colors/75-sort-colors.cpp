class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        for(int i = 0; i <= high; i++){
            if(nums[i] == 0){
                swap(nums[low], nums[i]);
                low++;
            }
            else if(nums[i] == 2){
                swap(nums[i], nums[high]);
                high--;
                i--;
            }
        }
    }
};