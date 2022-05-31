class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        unordered_set<string> res;
        for(int i = 0; i < n - k + 1; i++)
            res.insert(s.substr(i, k));
        return (res.size() == pow(2, k));
    }
};