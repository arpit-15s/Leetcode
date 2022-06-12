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
    vector<int> preorder(TreeNode* root){
        if(root == NULL) return {};
        vector<int> res;
        vector<int> res1 = preorder(root -> left);
        vector<int> res2 = preorder(root -> right);
        for(int i: res1)
            res.push_back(i);
        res.push_back(root -> val);
        for(int i: res2)
            res.push_back(i);
        return res;
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> res = preorder(root);
        for(int i = 1; i < res.size(); i++){
            if(res[i] <= res[i - 1]) return false;
        }
        return true;
    }
};