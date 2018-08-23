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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }
        int p = 0; 
        int q = nums.size() - 1;
        return helper(nums, p, q);
    }
    
    TreeNode* helper(vector<int>& nums, int begin, int end) {
        if (begin > end) {
            return NULL;
        }
        int mid = begin + (end - begin) / 2;
        TreeNode *result = new TreeNode(nums[mid]);
        result->left = helper(nums, begin, mid - 1);
        result->right = helper(nums, mid + 1, end);
        return result;
    }
};