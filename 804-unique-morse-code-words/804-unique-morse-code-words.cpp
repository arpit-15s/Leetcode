class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> encoding = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> res;
        for(string s:words){
            string temp;
            for(char c: s){
                temp += encoding[c - 'a'];
            }
            res.insert(temp);
        }
        return res.size();
    }
};