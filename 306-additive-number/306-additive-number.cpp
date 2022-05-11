class Solution {
public:
    string util_sum(string s1, string s2){
        // cout << s1 << "..." << s2 << "..." << s3 << endl;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        string ans;
        int carry = 0, i;
        for(i = 0; i < min(s1.length(), s2.length()); i++){
            int temp = (s1[i] - '0') + (s2[i] - '0') + carry;
            carry = temp / 10;
            temp %= 10;
            ans += to_string(temp);
        }
        
        while(i < s1.length()){
            int temp = (s1[i] - '0') + carry;
            carry = temp / 10;
            temp %= 10;
            ans += to_string(temp);
            i++;
        }
        
        while(i < s2.length()){
            int temp = (s2[i] - '0') + carry;
            carry = temp / 10;
            temp %= 10;
            ans += to_string(temp);
            i++;
        }
        
        if(carry != 0) ans += (char)(carry + '0');
        // cout << ans << " -> " << s3 << endl;
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    bool check(string num1, string num2, string num3){
        cout << num1 << " " << num2 << " " << num3 << endl;
        if((num1.length() > 1 && num1[0] == '0') || (num2.length() > 1 && num2[0] == '0')) return false;
        string sum = util_sum(num1, num2);
        if(sum == num3) return true;
        else if((sum.length() >= num3.length()) || (num3.substr(0, sum.length()) != sum)) return false;
        return check(num2, sum, num3.substr(sum.length()));
    }
    
    bool isAdditiveNumber(string num) {
        bool ans = false;
        for(int i = 1; i <= num.size() / 2; i++){
            for(int j = 1; j <= (num.size() - i) / 2; j++){
                ans |= check(num.substr(0, i), num.substr(i, j), num.substr(i + j));
                if(ans) return true;
            }
        }
        return false;
    }
};