class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        n *= n;
        priority_queue<int> pq;
        for(vector<int> v: matrix){
            for(int i: v){
                pq.push(i);
            }
        }
        while(n - k){
            pq.pop();
            n--;
        }
        return pq.top();
    }
};