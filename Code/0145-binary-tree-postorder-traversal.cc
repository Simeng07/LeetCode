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
    // recrusion:
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     f(root, result);
    //     return result;
    // }
    
    // void f(TreeNode* root, vector<int>& result) {
    //     if (root == NULL) return;
    //     f(root->left, result);
    //     f(root->right, result);
    //     result.push_back(root->val);
    // }
    
    // iteration:  
    // should do some research and solve it better
    // root-right-left then revert
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            // top & pop
            TreeNode* node = s.top();
            s.pop();
            result.push_back(node->val);
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};