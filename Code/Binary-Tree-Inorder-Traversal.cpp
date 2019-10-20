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
    vector<int> inorderTraversal(TreeNode* root) {
        // left -> root -> right
        vector<int> result;
        stack<TreeNode*> s;
        getLeft(root, s);
        while(!s.empty()) {
            // top & pop
            TreeNode* node = s.top();
            s.pop();
            result.push_back(node->val);
            getLeft(node->right, s);
        }
        return result;
    }
    
    // most left one
    void getLeft(TreeNode* node, stack<TreeNode*>& s) {
        while(node) {
            s.push(node);
            node = node->left;
        }
    }
};