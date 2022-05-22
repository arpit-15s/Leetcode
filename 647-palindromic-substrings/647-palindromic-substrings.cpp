class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), count = 0;
        vector<vector<bool>> tab(n, vector<bool>(n, 0));
        for(int g = 0; g < n; g++){
            for(int i = 0, j = g; j < n; i++, j++){
                if(g == 0){
                    tab[i][j] = 1;
                    count++;
                }
                else if(g == 1){
                    if(s[i] == s[j]){
                        tab[i][j] = 1;
                        count++;
                    }
                }
                else{
                    if(s[i] == s[j] && tab[i + 1][j - 1] == 1){
                        tab[i][j] = 1;
                        count++;
                    }
                }
            }
        }
        return count;
    }
};