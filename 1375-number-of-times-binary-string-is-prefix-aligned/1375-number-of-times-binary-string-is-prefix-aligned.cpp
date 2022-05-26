class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size();
        int maxx = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            maxx = max(flips[i], maxx);
            if(maxx == i + 1) count++;
        }
        return count;
    }
};