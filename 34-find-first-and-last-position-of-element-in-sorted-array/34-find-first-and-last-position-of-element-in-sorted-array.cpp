class Solution {
public:
    int binSearch(vector<int>& nums, int target, int pos){
        int n = nums.size();
        int start = 0, end = n - 1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            // cout << mid << endl;
            if(nums[mid] == target){
                if((mid + pos < 0) || (mid + pos == n) || (nums[mid] == target && nums[mid + pos] != target))
                   return mid;
                else{
                    if(pos == -1)
                        end = mid - 1;
                    else
                        start = mid + 1;
                }
            }
            else if(nums[mid] < target)
                start = mid + 1;
            else if(nums[mid] > target)
                end = mid - 1;
            
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binSearch(nums, target, -1), binSearch(nums, target, 1)};
    }
};