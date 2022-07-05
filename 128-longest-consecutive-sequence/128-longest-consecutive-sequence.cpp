class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int i: nums){
            set.insert(i);
        }
        int max_count = 0;
        for(int i: set){
            if(set.find(i - 1) == set.end()){
                int count = 0;
                while(set.find(i + count) != set.end()){
                    // cout << i + count << "k" << endl;
                    // set.erase(i + count);
                    count++;
                }
                max_count = max(count, max_count);
            }
        }
        return max_count;
    }
};