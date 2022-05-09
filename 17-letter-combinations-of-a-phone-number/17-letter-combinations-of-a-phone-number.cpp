class Solution {
public:
    vector<string> combination_util(string digits, unordered_map<int, vector<string>> map){
        if(digits.length() == 0) return {};
        if(digits.length() == 1){
            return map[digits[0] - '0'];
        } 
            
        vector<string> res1 = combination_util(digits.substr(1), map);
        vector<string> res;
        for(string i: map[digits[0] - '0']){
            for(string j: res1)
                res.push_back(i + j);
        }
        return res;
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<string>> map;
        map[2] = {"a", "b", "c"};
        map[3] = {"d", "e", "f"};
        map[4] = {"g", "h", "i"};
        map[5] = {"j", "k", "l"};
        map[6] = {"m", "n", "o"};
        map[7] = {"p", "q", "r", "s"};
        map[8] = {"t", "u", "v"};
        map[9] = {"w", "x", "y", "z"};
        // for(auto it = map.begin(); it != map.end(); it++){
        //     for(string s: it -> second)
        //         cout << s << " ";
        //     cout << endl;
        // }
        return combination_util(digits, map);
    }
};