class Solution {
public:
    vector<vector<int>> generate_permutations(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return {{nums[0]}};
        vector<vector<int>> res;
        unordered_set<int> set;
        for(int i = 0; i < n; i++){
            if(set.find(nums[i]) == set.end()){
                vector<int> temp(nums);
                temp.erase(temp.begin() + i);
                vector<vector<int>> temp_res = generate_permutations(temp);
                for(vector<int> it: temp_res){
                    it.push_back(nums[i]);
                    res.push_back(it);
                }
                temp_res.clear();
                set.insert(nums[i]);
            }
        }
        return res;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> res = generate_permutations(nums);
        set<vector<int>> set;
        for(int i = res.size() - 1; i >= 0; i--){
            if(set.find(res[i]) != set.end()){
                res.erase(res.begin() + i);
            }
            else{
                set.insert(res[i]);
            }
        }
        
        return res;
    }
};