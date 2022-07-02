class Solution {
public:
    vector<long> calcLen(int length, vector<int> cuts){
        vector<long> len;
        for(int i = 0; i < cuts.size(); i++){
            if(i == 0){
                len.push_back(cuts[i]);
            }else{
                len.push_back(cuts[i] - cuts[i - 1]);
            }
        }
        len.push_back(length - cuts[cuts.size() - 1]);
        return len;
    }
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        vector<long> hLen, vLen;
        long mod = 1000000007;
        hLen = calcLen(h, horizontalCuts);
        vLen = calcLen(w, verticalCuts);
        
        long res = (*max_element(hLen.begin(), hLen.end()) * *max_element(vLen.begin(), vLen.end())) % mod;
        return res;
    }
};