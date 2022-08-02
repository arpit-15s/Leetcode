class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(vector<int> i: matrix){
            for(int j: i){
                pq.push(j);
                if(pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};