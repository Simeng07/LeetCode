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
    unordered_map<TreeNode*, int> m;
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (m.find(root) != m.end()) return m[root];
        int choose = root->val;
        if (root->left) choose += rob(root->left->left) + rob(root->left->right);
        if (root->right) choose += rob(root->right->left) + rob(root->right->right);
        int notChoose = rob(root->left) + rob(root->right);
        m[root] = max(choose, notChoose);
        return m[root];
    }
};