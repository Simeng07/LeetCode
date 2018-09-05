/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        if (!head->next->next) {
            return head->val == head->next->val;
        }
        int count = 0;
        ListNode* node = head;
        while (node) {
            count++;
            node = node->next;
        }
        
        ListNode* right = head;
        for (int i = 0; i < (count + 1) / 2; i++) {
            right = right->next;
        }
        
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next = current->next;
        for (int i = 0; i < count / 2 - 1; i++) {
            current->next = prev;
            prev = current;
            current = next;
            next = next->next;
        }
        current->next = prev;

        while (current && right) {
            if (current->val != right->val) {
                return false;
            }
            current = current->next;
            right = right->next;
        }
        
        return true;
        
        // 分两半比较，把前半部分整个反过来
    }
};