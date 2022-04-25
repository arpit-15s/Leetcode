class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0].push_back(1);
        if(numRows >= 2){
            res[1].push_back(1);
            res[1].push_back(1);
        }
        for(int i = 2; i < numRows; i++){
            int j = 0; 
            res[i].push_back(1);
            while(j < res[i - 1].size() - 1){
                res[i].push_back(res[i - 1][j] + res[i - 1][j + 1]);
                j++;
            }
            res[i].push_back(1);
        }
        return res;
    }
};