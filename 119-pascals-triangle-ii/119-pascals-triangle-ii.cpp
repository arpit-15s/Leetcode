class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res(rowIndex + 1);
        res[0].push_back(1);
        if(rowIndex != 0){
            res[1].push_back(1);
            res[1].push_back(1);
        }
        for(int i = 2; i <= rowIndex; i++){
            res[i].push_back(1);
            for(int j = 0; j < res[i - 1].size() - 1; j++){
                res[i].push_back(res[i - 1][j] + res[i - 1][j + 1]);
            }
            res[i].push_back(1);
        }
        return res[rowIndex];
    }
};