class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end());
        int start = n, end = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != nums2[i]){
                start = i;
                break;
            }
        }
        for(int i = n - 1; i > 0; i--){
            if(nums[i] != nums2[i]){
                end = i;
                break;
            }
        }
        
        return (end - start + 1 > 0)? end - start + 1: 0;
    }
};