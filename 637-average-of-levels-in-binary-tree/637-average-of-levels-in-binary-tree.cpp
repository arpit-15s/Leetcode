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
    vector<double> levelTraversal(TreeNode* root){
        vector<double> res;
        queue<TreeNode*> q;
        queue<int> q2;
        res.push_back(root -> val * 1.0);
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
            long long temp = 0, size = q2.size();
            while(!q2.empty()){
                temp += q2.front();
                q2.pop();
            }
            if(size != 0)
            res.push_back((temp * 1.0)/size);
            i = size;
        }
        return res;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL) return {};
        return levelTraversal(root);
    }
};