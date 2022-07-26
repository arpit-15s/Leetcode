/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findPath(TreeNode* root, TreeNode *p, vector<TreeNode*>& path){
        if(root == NULL) return;
        if(root == p){
            path.push_back(root);
            return;
        }
        findPath(root -> left, p, path);
        if(!path.empty()){
            path.push_back(root);
            return;
        } 
        findPath(root -> right, p, path);
        if(!path.empty()){
            path.push_back(root);
            return;
        }
        return;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p, path_q;
        findPath(root, p, path_p);
        findPath(root, q, path_q);
        // for(TreeNode* i: path_p)
        //     cout << i -> val << " ";
        // cout << endl;
        // for(TreeNode* i: path_q)
        //     cout << i -> val << " ";
        // cout << endl;
        for(int i = path_p.size() - 1, j = path_q.size() - 1; i >= 0 && j >= 0; i--, j--){
            if(path_p[i] != path_q[j]) return path_p[i + 1];
        }
        if(path_p.size() < path_q.size()) return path_p[0];
        if(path_p.size() > path_q.size()) return path_q[0];
        return 0;
    }
};