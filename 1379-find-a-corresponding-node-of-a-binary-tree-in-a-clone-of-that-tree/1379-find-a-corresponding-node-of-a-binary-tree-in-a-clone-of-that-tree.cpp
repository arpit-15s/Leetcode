/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == NULL || original == target)
            return cloned;
        TreeNode* res1 = getTargetCopy(original -> left, cloned -> left, target);
        TreeNode* res2 = getTargetCopy(original -> right, cloned -> right, target);
        return (res1 != NULL)? res1: res2;
    }
};