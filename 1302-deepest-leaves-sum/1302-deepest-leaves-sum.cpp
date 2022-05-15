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
    void sum(TreeNode* root, int level, unordered_map<int, int>& level_sum){
        if(root == NULL) return;
        sum(root -> left, level + 1, level_sum);
        sum(root -> right, level + 1, level_sum);
        level_sum[level] += root -> val;
        return;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        unordered_map<int, int> level_sum;
        sum(root, 0, level_sum);
        int max_level = 0;
        for(auto it = level_sum.begin(); it != level_sum.end(); it++){
            max_level = max(max_level, it -> first);
        }
        return level_sum[max_level];
    }
};