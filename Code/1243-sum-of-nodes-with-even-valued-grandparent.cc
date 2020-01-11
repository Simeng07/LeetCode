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
    int sumEvenGrandparent(TreeNode* root) {
        if (!root) {
            return result;
        }
        helper(root, false, false);
        return result;
    }
    
    void helper(TreeNode* root, bool parent, bool grandparent) {
        if (grandparent) {
            result += root->val;
        }
        if (root->left) {
            helper(root->left, (root->val % 2 == 0), parent);
        }
        if (root->right) {
            helper(root->right, (root->val % 2 == 0), parent);
        }
    }
};