class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj_ele = 0, count = 0;
        for(int i = 0; i < n; i++){
            if(count == 0){
                maj_ele = nums[i];
                count = 1;
            }
            else if(maj_ele == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return maj_ele;
    }
};