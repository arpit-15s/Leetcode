class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0;
        int len = 0, max_len = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')
                open++;
            else close++;
            if(open == close)
                len = open + close;
            else if(open < close){
                open = 0;
                close = 0;
            }
            max_len = max(max_len, len);
        }
        open = 0, close = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == ')')
                close++;
            else open++;
            if(open == close)
                len = open + close;
            else if(open > close){
                open = 0;
                close = 0;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};