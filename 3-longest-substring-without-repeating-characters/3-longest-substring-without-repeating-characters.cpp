class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> st;
        int j = -1, i = 0;
        int max_len = 0;
        while(i != n){
            if(st.find(s[i]) != st.end()){
                do{
                    j++;
                    st.erase(s[j]);
                    // cout << s.size()
                }while(s[j] != s[i]);
            }
            st.insert(s[i]);
            max_len = max(max_len, i - j);
            i++;
        }
        return max_len;
    }
};