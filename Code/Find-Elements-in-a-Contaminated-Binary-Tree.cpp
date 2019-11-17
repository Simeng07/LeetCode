/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
    unordered_set<int> values;
    void helper(TreeNode *node, int value) {
        if (!node) {
            return;
        }
        node->val = value;
        values.insert(value);
        helper(node->left, value * 2 + 1);
        helper(node->right, value * 2 + 2);
    }
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        values.insert(0);
        helper(root->left, 1);
        helper(root->right, 2);
    }
    
    bool find(int target) {
        if (values.find(target) != values.end()) {
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */