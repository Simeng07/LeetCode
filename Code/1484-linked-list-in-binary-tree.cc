/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        return helper(head, root, true);
    }
    
    bool helper(ListNode* head, TreeNode* root, bool allowGap) {
        if (!head) {
            return true;
        }
        if (!root) {
            return false;
        }
        
        if (head->val == root->val) {
            return helper(head->next, root->left, false) || helper(head->next, root->right, false) || (allowGap && helper(head, root->left, allowGap)) || (allowGap && helper(head, root->right, allowGap));
        } else {
            return (allowGap && helper(head, root->left, allowGap)) || (allowGap && helper(head, root->right, allowGap));
        }
    }
};