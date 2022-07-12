class Solution {
public:
    bool calcPermutation(vector<int>& matchsticks, int idx, vector<long> sets, int len){
        if(idx == matchsticks.size()){
            return true;
        }
        bool res = false;
        for(int i = 0; i < 4; i++){
            int j = i - 1;
            while(j != -1){
                if(sets[i] == sets[j])
                    break;
                j--;
            }
            if(j != -1) continue;
            sets[i] += matchsticks[idx];
            if(sets[i] <= len)
                res |= calcPermutation(matchsticks, idx + 1, sets, len);
            sets[i] -= matchsticks[idx];
        }
        return res;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int param = 0;
        for(int i: matchsticks)
            param += i;
        if(param % 4) return false;
        vector<long> sets(4);
        sort(matchsticks.begin(), matchsticks.end(), [](int a, int b){
            return a > b;
        });
        return calcPermutation(matchsticks, 0, sets, param / 4);
    }
};