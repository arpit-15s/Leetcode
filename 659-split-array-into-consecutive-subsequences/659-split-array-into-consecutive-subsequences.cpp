class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> left, end;
        for(int i: nums){
            left[i]++;
        }
        for(int i: nums){
            if(left[i] == 0) continue;
            left[i]--;
            if(end[i - 1] > 0){
                end[i - 1]--;
                end[i]++;
            } else if(left[i + 1] > 0 && left[i + 2] > 0){
                left[i + 2]--;
                left[i + 1]--;
                end[i + 2]++;
            }else
                return false;
        }
        return true;
    }
};