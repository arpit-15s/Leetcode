class Solution {
public:
    bool isAnagram(string s, string t) {
        int lens = s.length();
        int lent = t.length();
        if(lens != lent) return false;
        unordered_map<char, int> map;
        for(char c: s){
            map[c]++;
        }
        for(char c: t){
            if(map[c] == 0)
                return false;
            map[c]--;
        }
        return true;
    }
};