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
    int longestZigZag(TreeNode* root) {
        helper(0, root, true);
        helper(0, root, false);
        return result;
    }
    void helper(int current, TreeNode* node, bool isLeft) {
        result = max(current, result);
        if (isLeft) {
            if (node->right) {
                helper(current + 1, node->right, false);
            }
            if (node->left) {
                helper(1, node->left, true);
            }
        } else {
            if (node->left) {
                helper(current + 1, node->left, true);
            }
            if (node->right) {
                helper(1, node->right, false);
            }
        }
    }
};