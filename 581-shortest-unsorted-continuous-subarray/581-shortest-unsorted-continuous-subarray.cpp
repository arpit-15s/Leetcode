class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = n, right = 0;
        int maxl = INT_MIN;
        for(int i = 0; i < n; i++){
            maxl = max(maxl, nums[i]);
            if(maxl != nums[i])
                right = i;
        }
        int minr = INT_MAX;
        for(int i = n - 1; i >= 0; i--){
            minr = min(minr, nums[i]);\
                if(minr != nums[i])
                    left = i;
        }
        
        return max(right - left + 1, 0);
    }
};