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
    vector<string> result;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) {
            return result;
        }
        if (!root->left && !root->right) {
            result.push_back(to_string(root->val));
            return result;
        }
        helper(root->left, to_string(root->val));
        helper(root->right, to_string(root->val));
        return result;
    }
    void helper(TreeNode* root, string current) {
        if (!root) {
            return;
        }
        string added = current + "->" + to_string(root->val);
        if (!root->left && !root->right) {
            result.push_back(added);
        }
        helper(root->left, added);
        helper(root->right, added);
    }
};