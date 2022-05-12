class Solution {
public:
    bool compare(string s){
        string cmp = to_string(INT_MAX);
        if(s.length() > cmp.length()) return false;
        if(s.length() < cmp.length()) return true;
        for(int i = 0; i < s.length(); i++){
            if(s[i] < cmp[i]) return true;
            if(s[i] > cmp[i]) return false;
        }
        return true;
    }
    
    bool generate_fibonacci(string s1, string s2, string s3, vector<int>& res){
        // cout << s1 << " " << s2 << " " << s3 << endl;
        if((s1.length() > 1 && s1[0] == '0') || (s2.length() > 1 && s2[0] == '0')) return false;
        else if(!compare(s1) || !compare(s2)) return false;
        long num1 = stoi(s1);
        long num2 = stoi(s2);
        if(num1 + num2 > INT_MAX) return false;
        if(compare(s3)){
            int num3 = stoi(s3);
            // cout << num1 << "->" << num2 << "->" << num3 << endl;
            if(num1 + num2 <= INT_MAX && num1 + num2 == num3){
                res.push_back(num1);
                res.push_back(num2);
                res.push_back(num3);
                return true;
            }
        }
        int len = to_string(num1 + num2).length();
        if((compare(s3) && num1 + num2 > stoi(s3)) || (s3.substr(0, len) != to_string(num1 + num2))) return false;
        res.push_back(num1);
        return generate_fibonacci(s2, s3.substr(0, len), s3.substr(len), res);
    }
    
    vector<int> splitIntoFibonacci(string num) {
        int n = num.length();
        bool zero = false;
        for(char c: num){
            if(c != '0'){
                zero = true;
                break;
            }
        } 
        vector<int> res1(n, 0);
        if(!zero)  return res1;
        vector<int> res;
        for(int i = 1; i <= (n / 2) && compare(num.substr(0, i)); i++){
            for(int j = 1; j <= ((n - i) / 2) && compare(num.substr(i, j)); j++){
                bool x = generate_fibonacci(num.substr(0, i), num.substr(i, j), num.substr(i + j), res);
                if(x)
                    return res;
                res.clear();
            }
        }
        return res;
    }
};