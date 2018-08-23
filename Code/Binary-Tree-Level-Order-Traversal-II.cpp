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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        if (!root) {
            return result;
        }
        vector<vector<TreeNode *> > nodes;
        nodes.push_back({root});
        while (true) {
            vector<TreeNode *> current = nodes[nodes.size() - 1];
            vector<TreeNode *> child;
            for (int i = 0; i < current.size(); i++) {
                if (current[i]->left) {
                    child.push_back(current[i]->left);
                }
                if (current[i]->right) {
                    child.push_back(current[i]->right);
                }
            }
            if (child.size() > 0) {
                nodes.push_back(child);
            } else {
                break;
            }
        }
        for (int i = nodes.size() - 1; i >= 0; i--) {
            vector<TreeNode *> current = nodes[i];
            vector<int> value;
            for (int i = 0; i < current.size(); i++) {
                value.push_back(current[i]->val);
            }
            result.push_back(value);
        }
        return result;
    }
};