class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> s;
        int count = 0;
        for(int i: nums){
            if(s.find(k - i) != s.end() && s[k - i] != 0){
                count++;
                s[k - i]--;
            }
            else
                s[i]++;
        }
        return count;
    }
};