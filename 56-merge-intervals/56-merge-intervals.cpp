class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n  = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        // for(vector<int> i: intervals){
        //     for(int j: i)
        //         cout << j << " ";
        // }
        // cout << endl;
        vector<vector<int>> res;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= end){
                end = max(end, intervals[i][1]);
            }else{
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        res.push_back({start, end});
        return res;
    }
};