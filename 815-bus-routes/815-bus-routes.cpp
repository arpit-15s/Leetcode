class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int, vector<int>> stop;
        int n = routes.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < routes[i].size(); j++){
                stop[routes[i][j]].push_back(i);
            }
        }
        set<int> visited_stops, visited_buses;
        queue<int> q;
        int count = 1;
        for(int i: stop[source]){
            visited_buses.insert(i);
            for(int j: routes[i]){
                if(j == target) return count;
                visited_stops.insert(j);
                q.push(j);
            }
        }
        // for(auto it = stop.begin(); it != stop.end(); it++){
        //     cout << it -> first << " -> ";
        //     for(int i: stop[it -> first]){
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }
        while(!q.empty()){
            // cout << "kb" << endl;
            count++;
            queue<int> temp, temp2;
            // temp2 = q;
            // while(!temp2.empty()){
            //     cout << temp2.front() << " ";
            //     temp2.pop();
            // }
            // cout << endl;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int i: stop[node]){
                    if(visited_buses.find(i) == visited_buses.end()){
                        // cout << i << " ";
                        for(int j: routes[i]){
                            // cout << j << " ";
                            if(j == target) return count;
                            if(visited_stops.find(j) == visited_stops.end()){
                                temp.push(j);
                                visited_stops.insert(j);
                            }
                            // cout << endl;
                        }
                        visited_buses.insert(i);
                    }
                }
            }
            q = temp;
        }
        return -1;
    }
};