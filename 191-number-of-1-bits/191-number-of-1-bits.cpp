class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        // cout << n << endl;
        while(n){
            count += n & 1;
            n >>= 1;
            // cout << count << " " << n << endl;
        }
        return count;
    }
};