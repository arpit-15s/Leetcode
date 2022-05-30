class Solution {
public:
    int divide(int A, int B) {
        if (A == INT_MIN && B == -1) return INT_MAX;
        long a = abs(A), b = abs(B), res = 0, x = 0;
        while (a - b >= 0) {
            for (x = 0; a - (b << x) >= 0; x++);
            // {
            //     long temp = (b << x);
            //     cout << temp << " ";
            // }
            // cout << endl;
            res += 1 << (x - 1);
            a -= b << (x - 1);
        }
        return (A > 0) == (B > 0) ? res : -res;
    }
};