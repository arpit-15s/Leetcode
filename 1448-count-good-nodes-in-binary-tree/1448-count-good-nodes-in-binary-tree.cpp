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
    int findCount(TreeNode* root, int max_val){
        if(root == NULL) return 0;
        int ans = 0;
        if(root -> val >= max_val) ans++;
        max_val = max(max_val, root -> val);
        ans += findCount(root -> left, max_val);
        ans += findCount(root -> right, max_val);
        return ans;
    }
    
    int goodNodes(TreeNode* root) {
        return findCount(root, -10001);
    }
};