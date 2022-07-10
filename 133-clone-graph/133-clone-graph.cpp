/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void makeAdj(Node* node, set<Node*>& set, vector<pair<int, int>>& adj){
        set.insert(node);
        for(Node* i: node -> neighbors){
            adj.push_back(make_pair(node -> val, i -> val));
            if(set.find(i) == set.end()){
                makeAdj(i, set, adj);
            }
        }
        return;
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        // cout << node -> val << endl;
        if(node -> neighbors.size() == 0) return new Node(1);
        vector<pair<int, int>> adj;
        set<Node*> set;
        Node* temp_res = new Node();
        makeAdj(node, set, adj);
        unordered_map<int, Node*> map;
        for(pair<int, int> i: adj){
            // cout << i.first << "->" << i.second << endl;
            if(map.find(i.first) == map.end())
                map[i.first] = new Node(i.first);
            if(map.find(i.second) == map.end())
                map[i.second] = new Node(i.second);
            map[i.first] -> neighbors.push_back(map[i.second]);
            if(i.first == 1)
                temp_res = map[i.first];
        }
        return temp_res;
    }
};