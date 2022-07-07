class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        if(m + n != s3.length()) return false;
        vector<vector<bool>> tab(m + 1, vector<bool>(n + 1, false));
        
        tab[0][0] = true;
        for(int i = 1; i <= m; i++){
            if(s1[i - 1] == s3[i - 1])
                tab[i][0] = tab[i - 1][0];
        }
        for(int i = 1; i <= n; i++){
            if(s2[i - 1] == s3[i - 1])
                tab[0][i] = tab[0][i - 1];
        }
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s3[i + j - 1] == s1[i - 1])
                    tab[i][j] = tab[i - 1][j];
                if(s3[i + j - 1] == s2[j - 1])
                    tab[i][j] = tab[i][j] || tab[i][j - 1];
            }
        }
        return tab[m][n];
    }
}; 