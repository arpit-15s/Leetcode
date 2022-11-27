class Solution {
public:
    void generateCombinations(int open, int close, vector<string>& res, string ssf){
        // cout << "Open " << open << "\t" << "close " << close << endl;
        if(close == 0){
            res.push_back(ssf);
            return;
        }
        
        if(open > 0)
            generateCombinations(open - 1, close, res, ssf + "(");
        if(close > open)
            generateCombinations(open, close - 1, res, ssf + ")");
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateCombinations(n, n, res, "");
        return res;
    }
};