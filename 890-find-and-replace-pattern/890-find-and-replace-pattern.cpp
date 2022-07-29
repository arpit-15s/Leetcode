class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        int len = pattern.length();
        vector<string> res;
        for(string i: words){
            if(i.length() != len) continue;
            bool isDiff = false;
            unordered_map<char, char> map1, map2;
            map1[pattern[0]] = i[0];
            map2[i[0]] = pattern[0];
            for(int j = 1; j < len; j++){
                if(map1.find(pattern[j]) == map1.end())
                    map1[pattern[j]] = i[j];
                if(map2.find(i[j]) == map2.end())
                    map2[i[j]] = pattern[j];
                if(map1[pattern[j]] != i[j] || map2[i[j]] != pattern[j]){
                    isDiff = true;
                    break;
                }   
            }
            if(!isDiff) res.push_back(i);
        }
        return res;
    }
};