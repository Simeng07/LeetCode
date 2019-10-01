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
    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return result;
    }
    
    void helper(TreeNode *root, int current) {
        if (!root) {
            return;
        }
        current = current * 10 + root->val;
        if (!root->left && !root->right) {
            result += current;
        }
        if (root->left) {
            helper(root->left, current);
        }
        if (root->right) {
            helper(root->right, current);
        }
    }
};