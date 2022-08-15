class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> map;
        map["I"] = 1;
        map["IV"] = 4;
        map["V"] = 5;
        map["IX"] = 9;
        map["X"] = 10;
        map["XL"] = 40;
        map["L"] = 50;
        map["XC"] = 90;
        map["C"] = 100;
        map["CD"] = 400;
        map["D"] = 500;
        map["CM"] = 900;
        map["M"] = 1000;
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            string temp;
            temp += s[i];
            if(map.find(s.substr(i, 2)) != map.end()){
                res += map[s.substr(i, 2)];
                i++;
            }
            else
                res += map[temp];
        }
        return res;
    }
};