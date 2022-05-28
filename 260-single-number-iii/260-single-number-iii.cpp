class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int exor = 0;
        for(int i: nums){
            exor ^= i;
        }
        int res1 = 0, res2 = 0;
        int bit = 1;
        while(!(bit & exor)){
            bit <<= 1;
        }
        cout << exor << endl;
        for(int i: nums){
            if(bit & i){
                res1 ^= i;
            }
            else{
                res2 ^= i;
            }
        }
        return {res1, res2};
    }
};