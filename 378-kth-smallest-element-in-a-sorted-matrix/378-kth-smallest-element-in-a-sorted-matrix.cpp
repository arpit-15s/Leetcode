class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        n *= n;
        vector<int> pq;
        for(vector<int> v: matrix){
            for(int i: v){
                pq.push_back(i);
            }
        }
        sort(pq.begin(), pq.end());
        return pq[k - 1];
    }
};