class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> map;
        vector<int> val({1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1});
        vector<string> str({"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"});
        string res;
        for(int i = 0; num != 0; i++){
            while(num >= val[i]){
                num -= val[i];
                res += str[i];
                // cout << res << " " << num << endl;
            }
        }
        return res;
    }
};