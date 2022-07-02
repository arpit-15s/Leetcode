class Solution {
public:
    set<vector<int>> twoSum(vector<int>& nums, int tar){
        int n = nums.size();
        set<int> set1;
        set<vector<int>> res;
        for(int i: nums){
            if(set1.find(tar - i) != set1.end()){
                res.insert({-tar, min(i, tar - i), max(i, tar - i)});
            }
            set1.insert(i);
        }
        return res;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> res_temp;
        
        for(int i = 0; i < n - 2; i++){
            if(i == 0 || nums[i] != nums[i - 1]){
                vector<int> temp(nums.begin() + i + 1, nums.end());
                set<vector<int>> temp_res = twoSum(temp, -nums[i]);
                for(auto it = temp_res.begin(); it != temp_res.end(); it++){
                    res_temp.insert(*it);
                }
            }
        }
        vector<vector<int>> res(res_temp.begin(), res_temp.end());
        return res;
    }
};