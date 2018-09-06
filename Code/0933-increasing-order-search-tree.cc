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
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        
        TreeNode* right = increasingBST(root->right);
        root->right = right;
        TreeNode* left = increasingBST(root->left);
        root->left = NULL;
        
        if (!left) {
            return root;
        }
        
        TreeNode* leftlast = left;
        while (leftlast && leftlast->right) {
            leftlast = leftlast->right;
        }
        leftlast->right = root;
        return left;
    }
};