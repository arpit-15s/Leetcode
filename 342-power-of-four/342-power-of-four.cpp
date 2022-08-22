class Solution {
public:
    bool isPowerOfFour(unsigned int n) {
        if(!(n & (n - 1)) && n % 3 == 1) return true;
        return false;
    }
};