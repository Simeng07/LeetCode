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
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        int left = calHeight(root->left);
        int right = calHeight(root->right);
        return isBalanced(root->left) && isBalanced(root->right) && (abs(left - right) <= 1);
    }
    
    int calHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(calHeight(root->left), calHeight(root->right)) + 1;
    }
};