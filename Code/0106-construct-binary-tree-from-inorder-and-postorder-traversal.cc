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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;
        return helper(postorder, 0, postorder.size(), inorder, 0, inorder.size());
    }
    
    TreeNode* helper(vector<int>& postorder, int postbegin, int postend, vector<int>& inorder, int inbegin, int inend) {
        // tree:     8 4 10 3 6 9 11
        // Inorder   [3 4 6] 8 [9 10 11]
        // postorder [3 6 4]   [9 11 10] 8
        
        if (postbegin >= postend || inbegin >= inend) return NULL;
        int mid = postorder[postend - 1];
        int dis = find(inorder.begin() + inbegin, inorder.begin() + inend, mid) - inorder.begin() - inbegin;
        
        TreeNode* root = new TreeNode(mid);
        root->left = helper(postorder, postbegin, postbegin + dis, inorder, inbegin, inbegin + dis);
        root->right = helper(postorder, postbegin + dis, postend - 1, inorder, inbegin + dis + 1, inend);
        return root;
    }
};