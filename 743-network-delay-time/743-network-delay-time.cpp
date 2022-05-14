class Solution {
public:
    int dijkstras(vector<vector<pair<int, int>>>& graph, vector<bool>& visited, int src){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        int count = 0;
        while(!pq.empty()){
            pair<int, int> rem = pq.top();
            pq.pop();
            if(visited[rem.second] == true) continue;
            visited[rem.second] = true;
            count++;
            if(count == graph.size()) return rem.first;
            for(pair<int, int> i : graph[rem.second]){
                if(visited[i.second] == false)
                    pq.push({rem.first + i.first, i.second});
            }
        }
        return -1;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(int i = 0; i < times.size(); i++){
            graph[times[i][0] - 1].push_back({times[i][2], times[i][1] - 1});
        }
        vector<bool> visited(n, false);
        int res = dijkstras(graph, visited, k - 1);
        return res;
    }
};