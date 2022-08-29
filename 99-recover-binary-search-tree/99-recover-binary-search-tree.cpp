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
    void traverse(TreeNode* root, vector<TreeNode*>& preorder){
        if(root == NULL) return;
        traverse(root -> left, preorder);
        preorder.push_back(root);
        traverse(root -> right, preorder);
        return;
    }
    
    void recoverTree(TreeNode* root) {
        // if(root = NULL || (root -> left == NULL && root -> right == NULL)) return;
        vector<TreeNode*> preorder;
        traverse(root, preorder);
        int i = 0;
        for(; i < preorder.size() - 1; i++){
            if(preorder[i] -> val > preorder[i + 1] -> val){
                break;
            }
        }
        int j = i + 1;
        while(j != preorder.size()){
            if(preorder[j] -> val > preorder[i] -> val){
                swap(preorder[i] -> val, preorder[j - 1] -> val);
                return;
            }
            j++;
        }
        swap(preorder[i] -> val, preorder[preorder.size() - 1] -> val);
        for(TreeNode* node: preorder) cout << node -> val << " ";
        cout << endl;
        return;
    }
};