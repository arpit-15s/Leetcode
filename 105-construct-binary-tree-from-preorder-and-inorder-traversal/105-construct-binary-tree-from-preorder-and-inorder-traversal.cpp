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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size()) return NULL;
        if(preorder.size() == 1) return new TreeNode(preorder[0]);
        TreeNode *root = new TreeNode(preorder[0]);
        int idx = 0, preIdx = 0;
        while(inorder[idx] != preorder[0]) idx++;\
            
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + idx + 1);
        vector<int> rightPre(preorder.begin() + idx + 1, preorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin() + idx);
        vector<int> rightIn(inorder.begin() + idx + 1, inorder.end());
        
        root -> left = buildTree(leftPre, leftIn);
        root -> right = buildTree(rightPre, rightIn);
        return root;
    }
};