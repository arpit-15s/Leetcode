class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int max1 = INT_MIN;
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] < max1) return true;
            while(!st.empty() && nums[st.top()] < nums[i]){
                max1 = max(max1, nums[st.top()]);
                st.pop();
            }
            st.push(i);
        }
        return false;
    }
};