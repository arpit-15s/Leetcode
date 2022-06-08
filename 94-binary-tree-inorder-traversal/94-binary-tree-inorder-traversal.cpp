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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode*> st;
        st.push(root);
        vector<int> res;
        TreeNode* curr = root -> left;
        while((!st.empty() || curr != NULL)){
            while(curr != NULL){
                st.push(curr);
                curr = curr -> left;
            }
            int num = st.top() -> val;
            curr = st.top() -> right;
            st.pop();
            res.push_back(num);
        }
        return res;
    }
};