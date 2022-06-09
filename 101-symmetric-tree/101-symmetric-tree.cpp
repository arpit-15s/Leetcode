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
    bool traverseSubtree(TreeNode* left, TreeNode* right){
        // cout << left -> val << " " << right -> val << endl;
        if(left == NULL && right == NULL) return true;
        if((left == NULL && right != NULL) || (left != NULL && right == NULL)) return false;
        if(left -> val != right -> val) return false;
        
        return traverseSubtree(left -> left, right -> right) && traverseSubtree(left -> right, right -> left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL || (root -> left == NULL && root -> right == NULL)) return true;
        return traverseSubtree(root -> left, root -> right);
    }
};