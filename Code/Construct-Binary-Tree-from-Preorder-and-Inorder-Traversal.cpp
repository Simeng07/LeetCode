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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
    TreeNode* helper(vector<int>& preorder, int prebegin, int preend, vector<int>& inorder, int inbegin, int inend) {
        // tree        8 4 5 3 7 3
        // preorder    8 [4 3 3 7] [5]
        // inorder     [3 3 4 7] 8 [5]
        
        if (prebegin >= preend || inbegin >= inend) return NULL;
        int mid = preorder[prebegin];
        int dis = find(inorder.begin() + inbegin, inorder.begin() + inend, mid) - inorder.begin() - inbegin;
        
        TreeNode* root = new TreeNode(mid);
        root->left = helper(preorder, prebegin + 1, prebegin + 1 + dis, inorder, inbegin, inbegin + dis);
        root->right = helper(preorder, prebegin + 1 + dis, preend, inorder, inbegin + dis + 1, inend);
        return root;
    }
};