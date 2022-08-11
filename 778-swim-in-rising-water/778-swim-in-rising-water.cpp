class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int max_elevation = grid[0][0];
        pq.push(make_pair(-grid[0][0], make_pair(0, 0)));
        visited[0][0] = true;
        while(!pq.empty()){
            max_elevation = max(max_elevation, -pq.top().first);
            // pair<int, int> index = pq.top().second;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            // visited[index.first][index.second] = true;
            if(i == n - 1 && j == n - 1) return max_elevation;
            pq.pop();
            if(i - 1 >= 0 && !visited[i - 1][j]){
                pq.push(make_pair(-grid[i - 1][j], make_pair(i - 1, j)));
                visited[i - 1][j] = true;
            }if(j - 1 >= 0 && !visited[i][j - 1]){
                pq.push(make_pair(-grid[i][j - 1], make_pair(i, j - 1)));
                visited[i][j - 1] = true;
            }if(i + 1 < n && !visited[i + 1][j]){
                pq.push(make_pair(-grid[i + 1][j], make_pair(i + 1, j)));
                visited[i + 1][j] = true;
            }if(j + 1 < n && !visited[i][j + 1]){
                pq.push(make_pair(-grid[i][j + 1], make_pair(i, j + 1)));
                visited[i][j + 1] = true;
            }
        }
        return 0;
    }
};