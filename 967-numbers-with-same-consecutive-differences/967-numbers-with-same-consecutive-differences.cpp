class Solution {
public:
    void calcNumbers(int n, int k, set<string>& res, string ssf){
        if(ssf[0] == '0') return;
        if(n == 0){
            res.insert(ssf);
            return;
        }
        for(int i = 0; i < 10; i++){
            if(abs(ssf[ssf.length() - 1] - i - '0') == k){
                // cout << ssf[ssf.length() - 1] << " " << i << endl;
                calcNumbers(n - 1, k, res, ssf + to_string(i));
            }
        }
        return;
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        set<string> s;
        vector<int> res;
        for(int i = 0; i < 10; i++){
            calcNumbers(n - 1, k, s, to_string(i));
        }
        for(string st: s) res.push_back(stoi(st));
        return res;
    }
};