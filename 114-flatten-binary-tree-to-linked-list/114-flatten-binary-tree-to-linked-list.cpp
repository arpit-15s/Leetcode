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
    void flatten(TreeNode* root) {
        if(root == NULL || (root -> left == NULL && root -> right == NULL)) return;
        flatten(root -> left);
        flatten(root -> right);
        TreeNode *temp_left = root -> left;
        TreeNode *temp_right = root -> right;
        root -> left = NULL;
        root -> right = temp_left;
        if(temp_left == NULL){
            root -> right = temp_right;
            return;
        }
        while(temp_left -> right != NULL){
            temp_left = temp_left -> right;
        }
        temp_left -> right = temp_right;
        return;
    }
};