class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, set<pair<int, int>>& set){
        int n = grid.size();
        if(row < 0 || col < 0 || row == n || col == n || grid[row][col] == 0 || set.find(make_pair(row, col)) != set.end()) return;
        set.insert(make_pair(row, col));
        dfs(grid, row - 1, col, set);
        dfs(grid, row + 1, col, set);
        dfs(grid, row, col - 1, set);
        dfs(grid, row, col + 1, set);
        return;
    }
    
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>> q, set<pair<int, int>>& set){
        int n = grid.size();
        queue<pair<int, int>> temp;
        int dist = 0;
        while(!q.empty()){
            while(!q.empty()){
                pair<int, int> node = q.front();
                q.pop();
                int row = node.first;
                int col = node.second;
                if(row - 1 >= 0 && set.find(make_pair(row - 1, col)) == set.end()){
                    if(grid[row - 1][col] == 0){
                        temp.push(make_pair(row - 1, col));
                    }
                    else if(grid[row - 1][col] == 1)
                        return dist;   
                    set.insert(make_pair(row - 1, col));
                }
                if(col - 1 >= 0 && set.find(make_pair(row, col - 1)) == set.end()){
                    if(grid[row][col - 1] == 0){
                        temp.push(make_pair(row, col - 1));
                    }
                    else if(grid[row][col - 1] == 1)
                        return dist;
                    set.insert(make_pair(row, col - 1));
                }
                if(row + 1 < n && set.find(make_pair(row + 1, col)) == set.end()){
                    if(grid[row + 1][col] == 0){
                        temp.push(make_pair(row + 1, col));
                    }
                    else if(grid[row + 1][col] == 1)
                        return dist;
                    set.insert(make_pair(row + 1, col));
                }
                if(col + 1 < n && set.find(make_pair(row, col + 1)) == set.end()){
                    if(grid[row][col + 1] == 0){
                        temp.push(make_pair(row, col + 1));
                    }
                    else if(grid[row][col + 1] == 1)
                        return dist;
                    set.insert(make_pair(row, col + 1));
                }
                grid[row][col] = 2;
            }
            dist++;
            q = temp;
            while(!temp.empty()) temp.pop();
        }
        return 0;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int, int>> set;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    dfs(grid, i, j, set);
                    goto label_1;
                }
            }
        }
        label_1: queue<pair<int, int>> q;
        for(pair<int, int> i: set){
            // cout << i.first << " " << i.second << endl;
            q.push(i);
        }
        // return 0;
        return bfs(grid, q, set);
        
    }
};