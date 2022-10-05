class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        unordered_map<int, int> map;
        int sum = 0, count = 0;
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        for(int i = 0; i <= n; i++){
            int rem = prefix[i] - k;
            if(map.find(rem) != map.end())
                count += map[rem];
            map[prefix[i]]++;
        }
        return count;
    }
};