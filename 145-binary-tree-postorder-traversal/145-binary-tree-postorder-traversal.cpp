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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode*> s1;
        vector<int> res;
        s1.push(root);
        while(!s1.empty()){
            TreeNode* node = s1.top();
            s1.pop();
            if(node -> left != NULL)
                s1.push(node -> left);
            if(node -> right != NULL)
                s1.push(node -> right);
            
            res.push_back(node -> val);
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};