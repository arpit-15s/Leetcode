class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0) return 0;
        unordered_map<int, int> map;
        int minIndex = -1, maxIndex = -1;
        int maxlen = 0;
        for(int i = 0; i < n; i++){
            if(map.find(s[i]) != map.end()){
                int j = minIndex;
                do{
                    j++;
                    map.erase(s[j]);
                }
                while(s[i] != s[j]);
                minIndex = j;
            }
            map[s[i]]++;
            maxIndex++;
            cout << maxIndex << " -> " << minIndex << endl;
            maxlen = max(maxlen, maxIndex - minIndex);
        }
        return maxlen;
    }
};