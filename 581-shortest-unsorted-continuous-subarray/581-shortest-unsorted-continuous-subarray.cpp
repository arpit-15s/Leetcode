class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> minrhs(n), maxlhs(n);
        int maxl = INT_MIN;
        for(int i = 0; i < n; i++){
            maxlhs[i] = max(maxl, nums[i]);
            maxl = max(maxl, nums[i]);
        }
        int minr = INT_MAX;
        for(int i = n - 1; i >= 0; i--){
            minrhs[i] = min(nums[i], minr);
            minr = min(minr, nums[i]);
        }
        
        int i = 0, j = n - 1;
        while( i < n && minrhs[i] == nums[i])i++;
        while(j >= 0 && maxlhs[j] == nums[j])j--;
        return max(j - i + 1, 0);
    }
};