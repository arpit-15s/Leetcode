class Solution {
public:
    int binSearch(vector<int> nums, int k){
        int start = 0, end = nums.size() - 1;
        if(nums[end] <= k) return nums.size();
        if(nums[0] > k) return 0;
        while(start != end){
            int mid = start + (end - start) / 2;
            if(nums[mid] <= k && nums[mid + 1] > k) return mid + 1;
            else if(nums[mid] <= k) start = mid + 1;
            else end = mid;
        }
        return 0;
    }
    
    int findLesserCount(vector<vector<int>>& matrix, int k){
        int n = matrix.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            count += binSearch(matrix[i], k);
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int start = matrix[0][0];
        int end = matrix[n - 1][n - 1];
        while(start != end){
            int mid = start + (end - start) / 2;
            int count = findLesserCount(matrix, mid);
            cout << mid << endl;
            if(count < k)
                start = mid + 1;
            else 
                end = mid;
        }
        return start;
    }
};