class Solution {
public:
    vector<vector<int>> util_combination(int k, int n, string s, int idx){
        if(n == 0 && k == 0){
            vector<int> res;
            for(char i: s){
                
                res.push_back(stoi(to_string(i - '0')));
            }
           
            return {res};
        }
        if(idx >= 9 || n < 0 || k == 0) return {{}};
        vector<vector<int>> res1 = util_combination(k, n, s, idx + 1);
        vector<vector<int>> res2 = util_combination(k - 1, n - idx - 1, s + to_string(idx + 1), idx + 1);
        vector<vector<int>> res;
            
        for(vector<int> i: res1){
            if(i.size())
                res.push_back(i);
        }
        for(vector<int> i: res2){
            if(i.size())
                res.push_back(i);
        }
        
        return res;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        return util_combination(k, n, "", 0);
    }
};