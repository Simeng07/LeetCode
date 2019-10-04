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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        int count = 1;
        while (!q.empty()) {
            vector<int> v;
            while (count--) {
                TreeNode *node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(v);
            count = q.size();
        }
        return result;
    }
};