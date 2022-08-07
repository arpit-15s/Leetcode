class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string end = "123450";
        vector<vector<int>> next = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        string begin = "";
        for(vector<int> i: board){
            for(int j: i)
                begin += to_string(j);
        }
        set<string> set;
        set.insert(begin);
        queue<pair<string, int>> q;
        q.push(make_pair(begin, 0));
        while(!q.empty()){
            auto p = q.front(); q.pop();
            string curr = p.first;
            int dist = p.second;
            if(curr == end) return dist;
            int idx = curr.find("0");
            for(int i: next[idx]){
                swap(curr[idx], curr[i]);
                if(set.find(curr) == set.end()){
                    q.push(make_pair(curr, dist + 1));
                    set.insert(curr);
                }
                swap(curr[idx], curr[i]);
            }
        }
        return -1;
    }
};