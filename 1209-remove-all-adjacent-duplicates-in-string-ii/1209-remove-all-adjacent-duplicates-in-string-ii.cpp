class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int, int>> st;
        for(char c: s){
            if(st.empty() || st.top().first != c){
                st.push({c, 1});
            }
            else if((st.top()).first == c) {
                if((st.top()).second == k - 1){
                    while(!st.empty() && (st.top()).first == c){
                        st.pop();
                    }
                }
                else{
                    st.push({c, (st.top()).second + 1});
                }
            }
        }
        string res;
        while(!st.empty()){
            res += (st.top()).first;
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};