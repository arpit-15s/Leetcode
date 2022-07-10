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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q1, q2;
        vector<int> res;
        q1.push(root);
        // cout << q1.front() -> val << endl;
        while(!q1.empty()){
            // cout << "kb" << endl;
            while(!q1.empty()){
                // cout << q1.front() -> val << endl;
                if(q1.front() -> left)
                    q2.push(q1.front() -> left);
                if(q1.front() -> right)
                    q2.push(q1.front() -> right);
                if(q1.size() == 1)
                    res.push_back(q1.front() -> val);
                q1.pop();
            }
            q1 = q2;
            while(!q2.empty()) q2.pop();
                
        }
        return res;
    }
};