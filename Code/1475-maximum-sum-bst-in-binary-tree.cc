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
    int result = 0;
public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return result;
    }
    
    vector<int> helper(TreeNode* node) {
        if (!node) {
            return {0, 0, 0};
        }
        
        vector<int> left = helper(node->left);
        vector<int> right = helper(node->right);
        if (left[0] == INT_MIN || right[0] == INT_MIN) {
            return {INT_MIN, 0, 0};
        }
        
        if ((!node->right || node->val < right[1]) && (!node->left || node->val > left[2])) {
            int current = (node->left ? left[0] : 0) + (node->right ? right[0] : 0) + node->val;
            result = max(result, current);
            return {current, (node->left ? left[1] : node->val), (node->right ? right[2] : node->val)};
        }
        
        return {INT_MIN, 0, 0};
    }
};