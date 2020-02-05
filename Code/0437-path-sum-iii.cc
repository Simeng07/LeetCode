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
    int pathSum(TreeNode* root, int sum) {
        helper(root, sum, false);
        return result;
    }
    void helper(TreeNode* root, int sum, bool must) {
        if (!root) {
            return;
        }
        if (sum == root->val) {
            result++;
        }
        
        if (!must) {
            helper(root->left, sum, false);
            helper(root->right, sum, false);
        }
        helper(root->left, sum - root->val, true);
        helper(root->right, sum - root->val, true);
    }
};