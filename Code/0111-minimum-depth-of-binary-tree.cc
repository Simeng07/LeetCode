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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        vector<TreeNode *> parent;
        vector<TreeNode *> child;
        parent.push_back(root);
        int result = 1;
        while (true) {
            child.clear();
            for (int i = 0; i < parent.size(); i++) {
                if (parent[i]->left) {
                    child.push_back(parent[i]->left);
                }
                if (parent[i]->right) {
                    child.push_back(parent[i]->right);
                }
                if (!parent[i]->left && !parent[i]->right) {
                    return result;
                }
            }
            parent = child;
            result++;
        }
    }
};