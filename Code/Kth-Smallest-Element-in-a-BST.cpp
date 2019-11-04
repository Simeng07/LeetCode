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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> s;
        TreeNode* p = root;
       
        while (p || !s.empty()) {
            while (p) {
                // push, not push_back
                s.push(p);
                p = p->left;
            }
            p = s.top();
            if (--k == 0) return p->val;
            s.pop();
            p = p->right;
        }
        return -1;
    }
};