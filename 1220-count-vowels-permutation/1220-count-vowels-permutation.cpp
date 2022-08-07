class Solution {
public:
    int countVowelPermutation(int n) {
        if(n == 1) return 5;
        unordered_map<char, long> map;
        map['a'] = 1;
        map['e'] = 1;
        map['i'] = 1;
        map['o'] = 1;
        map['u'] = 1;
        int mod = pow(10, 9) + 7;
        n--;
        long res = 0;
        while(n--){
            vector<long> temp(5, 0);
            temp[1] += map['a'] % mod;
            temp[0] += map['e'] % mod;
            temp[2] += map['e'] % mod;
            temp[0] += map['i'] % mod;
            temp[1] += map['i'] % mod;
            temp[3] += map['i'] % mod;
            temp[4] += map['i'] % mod;
            temp[2] += map['o'] % mod;
            temp[4] += map['o'] % mod;
            temp[0] += map['u'] % mod;
            res = (temp[0] + temp[1] + temp[2] + temp[3] + temp[4]) % mod;
            map['a'] = temp[0];
            map['e'] = temp[1];
            map['i'] = temp[2];
            map['o'] = temp[3];
            map['u'] = temp[4];
        }
        return res;
    }
};