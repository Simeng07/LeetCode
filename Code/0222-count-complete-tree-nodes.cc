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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int h = 0;
        TreeNode* p = root;
        while (p->left) {
            h++;
            p = p->left;
        }
        int fullNodes = pow(2, h) - 1;
        int low = 0, high = pow(2, h) - 1;
        while (low <= high) {
            int n = (low + high) / 2;
            int mask = 0;
            if (h > 0) mask = (1 << (h - 1));
            p = root;
            while (mask) {
                if (mask & n) p = p->right;
                else p = p->left;
                mask >>= 1;
            }
            if (!p) high = n - 1;
            else low = n + 1;
        }
        return fullNodes + low;
    }
};