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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> res;
        while(!q.empty()){
            queue<TreeNode*> temp;
            double avg = 0, count = 0;
            while(!q.empty()){
                TreeNode* node = q.front(); q.pop();
                if(node -> left != NULL) temp.push(node -> left);
                if(node -> right != NULL) temp.push(node -> right);
                avg += node -> val;
                count++;
            }
            res.push_back(avg / count);
            q = temp;
        }
        return res;
    }
};