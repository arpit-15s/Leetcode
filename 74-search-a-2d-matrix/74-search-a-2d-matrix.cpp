class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1;
        int tar = matrix[i][j];
        while(i >= 0 && j >= 0 && i < m && j < n){
            if(tar == target) return true;
            if(tar < target && i + 1 < m){
                i++;
            }
            else if(tar > target && j - 1 >= 0){
                j--;
            }
            else return false;
            tar = matrix[i][j];
        }
        return false;
    }
};