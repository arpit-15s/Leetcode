class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while(num){
            (num % 2)? num--: num /= 2;
            count++;
        }
        return count;
    }
};