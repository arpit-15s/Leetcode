class Solution {
public:
    struct Point{
        int x;
        int y;
        int count;
    };
        
    int dx[8] = {1,1,1,-1,-1,-1,0,0};
    int dy[8] = {-1,1,0,-1,1,0,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return -1;
        int row = grid.size();
        int col = grid[0].size();
        queue<Point> q;
        q.push({0,0,1});
        grid[0][0] = -1;
        
        while(!q.empty()){
            Point P = q.front();
            q.pop();
            if(P.x == row - 1 && P.y == col - 1)
                return P.count;
            
            for(int i = 0; i < 8; i++){
                int x = P.x + dx[i];
                int y = P.y + dy[i];
                
                if(x >= 0 && y >= 0 && x < row && y < col && grid[x][y] == 0){
                    q.push({x, y, P.count + 1});
                    grid[x][y] = -1;
                }
            }
        }
        return -1;
    }
};