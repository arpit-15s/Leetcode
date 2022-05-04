class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        //st.push(s[0]);
        int i = 0;
        while(i != s.length()){
            if(s[i] != ']'){
                st.push(s[i]);
            }
            else{
                string temp;
                while(st.top() != '['){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(), temp.end());
                string num;
                while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
                    num += st.top();
                    cout << num << " ";
                    st.pop();
                }
                reverse(num.begin(), num.end());
                int mul = stoi(num);
                string temp2="";
                while(mul--){
                    temp2 += temp;
                }
                for(char j: temp2) st.push(j);
            }
            i++;
        }
        string res="";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};