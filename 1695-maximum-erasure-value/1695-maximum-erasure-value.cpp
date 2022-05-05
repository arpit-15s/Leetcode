class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        int minIndex = -1;
        long maxval = 0, localmax = 0;
        for(int i = 0; i < n; i++){
            localmax += nums[i];
            if(map.find(nums[i]) != map.end()){
                int j = minIndex;
                do{
                    j++;
                    localmax -= nums[map[nums[j]] - 1];
                    map.erase(nums[j]);
                }
                while(nums[i] != nums[j]);
                minIndex = j;
            }
            map[nums[i]] = i + 1;
            maxval = max(maxval, localmax);
        }
        return maxval;
    }
};