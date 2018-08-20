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
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return compareSymmetric(root->left, root->right);
    }
    bool compareSymmetric(TreeNode *t1, TreeNode *t2) {
        if (t1 && t2) {
            return (t1->val == t2->val) && compareSymmetric(t1->left, t2->right) && compareSymmetric(t1->right, t2->left);
        }
        if (!t1 && !t2) {
            return true;
        }
        return false;
    }
};