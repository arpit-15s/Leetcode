class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pas_tri(numRows);
        pas_tri[0].push_back(1);
        for(int i = 1; i < numRows; i++){
            pas_tri[i].push_back(1);
            for(int j = 1; j < pas_tri[i - 1].size(); j++){
                pas_tri[i].push_back(pas_tri[i - 1][j - 1] + pas_tri[i - 1][j]);
            }
            pas_tri[i].push_back(1);
        }
        return pas_tri;
    }
};