/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelTraversal(TreeNode* root){
        vector<vector<int>> res;
        queue<TreeNode*> q;
        queue<int> q2;
        res.push_back({root -> val});
        q.push(root);
        int i = 1;
        while(!q.empty()){
            while(i != 0 && !q.empty()){
                TreeNode* node = q.front();
                // cout << node -> val << endl;
                q.pop();
                if(node -> left != NULL){
                    q.push(node -> left);
                    q2.push(node -> left -> val);
                }
                    
                if(node -> right != NULL){
                    q.push(node -> right);
                    q2.push(node -> right -> val);
                }
                    
                i--;
            }
            vector<int> temp;
            while(!q2.empty()){
                temp.push_back(q2.front());
                q2.pop();
            }
            if(temp.size())
            res.push_back(temp);
            i = temp.size();
        }
        return res;
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> res =  levelTraversal(root);
        reverse(res.begin(), res.end());
        return res;
    }
};