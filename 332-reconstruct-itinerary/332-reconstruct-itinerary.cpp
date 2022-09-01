class Solution {
public:
    void dfs(string src, map<string, priority_queue<string, vector<string>, greater<string>>>& graph, vector<string>& res){
        while(!graph[src].empty()){
            string node = graph[src].top();
            graph[src].pop();
            dfs(node, graph, res);
        }
        res.push_back(src);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for(vector<string> ticket: tickets){
            graph[ticket[0]].push(ticket[1]);
        }
        vector<string> res;
        dfs("JFK", graph, res);
        reverse(res.begin(), res.end());
        return res;
    }
};