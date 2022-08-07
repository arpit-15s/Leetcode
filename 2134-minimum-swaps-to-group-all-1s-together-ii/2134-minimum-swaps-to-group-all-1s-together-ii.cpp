class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]) count1++;
            nums.push_back(nums[i]);
        }
        if(!count1) return 0;
        int count0 = 0;
        int j = 0;
        while(j != count1){
            if(!nums[j]) count0++;
            j++;
        }
        int res = n;
        for(int i = 0; j < 2 * n; i++, j++){
            res = min(res, count0);
            if(nums[i] == 0) count0--;
            if(nums[j] == 0) count0++;
        }
        return res;
    }
};