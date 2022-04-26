class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<vector<int>> res(nums.size(), vector<int>(nums.size(), 0));
        res[0] = nums;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < res[i - 1].size() - 1; j++){
                res[i][j] = res[i - 1][j] + res[i - 1][j + 1];
                res[i][j] %= 10;
            }
        }
        return res[res.size() - 1][0];
    }
};