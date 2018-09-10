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
    unordered_map<TreeNode *, unordered_set<int>> m;
public:
    int pathSum(TreeNode* root, int sum) {
        helper(root, sum, sum, 0);
        return result;
    }
    void helper(TreeNode* root, int sum, int currentSum, int length) {
        if (!root) {
            return;
        }
        if (m.find(root) == m.end() || m[root].find(length) == m[root].end()) {
            m[root].insert(length);
        } else {
            return;
        }
        if (root->val == currentSum) {
            result++;
        }
        helper(root->left, sum, currentSum - root->val, length + 1);
        helper(root->right, sum, currentSum - root->val, length + 1);
        helper(root->left, sum, sum, 0);
        helper(root->right, sum, sum, 0);
    }
};