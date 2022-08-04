class Solution {
public:
    int mirrorReflection(int p, int q) {
        int count = 1;
        while((count * p) % q) count++;
        if((count) % 2 == 0) return 0;
        if(((count * p) / q) % 2) return 1;
        return 2;
    }
};