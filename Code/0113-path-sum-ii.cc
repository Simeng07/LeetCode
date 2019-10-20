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
    vector<vector<int> > result;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        helper(tmp, root, sum);
        return result;
    }
    // backtracking?
    void helper(vector<int>& tmp, TreeNode* root, int sum) {
        if (!root) return;
        tmp.push_back(root->val);
        if (!root->left && !root->right && sum == root->val) result.push_back(tmp);
        helper(tmp, root->left, sum - root->val);
        helper(tmp, root->right, sum - root->val);
        // tmp.pop_back(); 
        tmp.pop_back();
    }
};