class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> pos;
        for(string s: words){
            int temp = 0;
            for(char c: s){
                temp |= (1 << ((int)(c & 31) - 1));
            }
            pos.push_back(temp);
        }
        int max_len = 0;
        for(int i = 0; i < pos.size(); i++){
            for(int j = i + 1; j < pos.size(); j++){
                if(!(pos[i] & pos[j])){
                    int l1 = words[i].length(), l2 = words[j].length();
                    max_len = max(max_len, l1 * l2);
                }
            }
        }
        return max_len;
    }
};