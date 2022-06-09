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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<TreeNode*> temp;
            while(!q.empty()){
                temp.push_back(q.front());
                q.pop();
            }
            vector<int> temp_res;
            for(TreeNode* i: temp){
                if(i -> left != NULL)
                    q.push(i -> left);
                if(i -> right != NULL)
                    q.push(i -> right);
                temp_res.push_back(i -> val);
            }
            res.push_back(temp_res);
        }
        return res;
    }
};