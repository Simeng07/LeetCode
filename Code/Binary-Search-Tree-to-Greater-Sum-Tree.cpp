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
    vector<TreeNode*> list;
public:
    TreeNode* bstToGst(TreeNode* root) {
        helper(root);
        int former = 0;
        for (TreeNode *node : list) {
            node->val += former;
            former = node->val;
        }
        return root;
    }
    
    void helper(TreeNode *root) {
        if (!root) {
            return;
        }
        helper(root->right);
        list.push_back(root);
        helper(root->left);
    }
};