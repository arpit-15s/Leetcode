/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};
        vector<vector<int>> res;
        queue<Node*> q;
        res.push_back({root -> val});
        q.push(root);
        while(!q.empty()){
            vector<Node*> temp;
            while(!q.empty()){
                Node* node = q.front(); q.pop();
                for(Node* child: node -> children){
                    if(child != NULL) temp.push_back(child);
                }
            }
            res.push_back({});
            for(Node* child: temp){
                res[res.size() - 1].push_back(child -> val);
                q.push(child);
            }
            if(res[res.size() - 1].size() == 0) res.pop_back();
        }
        return res;
    }
};