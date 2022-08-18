class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> map;
        vector<pair<int, int>> freq;
        for(int i: arr){
            map[i]++;
        }
        for(auto i: map){
            freq.push_back(make_pair(i.first, i.second));
        }
        sort(freq.begin(), freq.end(), [](pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        });
        int count = 0;
        for(int i = 0; i < n; i++){
            count += freq[i].second;
            if(count >= n/2) return i + 1;
        }
        return -1;
    }
};