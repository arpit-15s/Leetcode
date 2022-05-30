class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        
        for(int i = 0; i <= s.length(); i++){
            if(dp[i]){
                for(string str: wordDict){
                    if(s.substr(i, str.length()) == str)
                        dp[i + str.length()] = true;
                }
            }
        }
        return dp[s.length()];
    }
};