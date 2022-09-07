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
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";
        string left, right;
        if(root -> left != NULL)
        left = tree2str(root -> left);
        if(root -> right != NULL)
        right = tree2str(root -> right);
        if(left != "" && right != "")
            return to_string(root -> val) + '(' + left + ')' + '(' + right + ')';
        if(right != "")
            return to_string(root -> val) + '(' + left + ')' + '(' + right + ')';
        if(left != "")
            return to_string(root -> val) + '(' + left + ')';
        return to_string(root -> val);
        
    }
};