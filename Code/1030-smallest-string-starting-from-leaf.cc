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
    string result;
public:
    string smallestFromLeaf(TreeNode* root) {
        result = "";
        helper(root, "");
        return result;
    }
    
    void helper(TreeNode *node, string current) {
        if (!node) {
            return;
        }
        char c = node->val + 'a';
        string added = c + current;
        if (!node->left && !node->right) {
            if (result == "" || result > added) {
                result = added;
            }
            return;
        }
        helper(node->left, added);
        helper(node->right, added);
    }
};