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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* result = head;
        while (result && result->val == val) {
            result = result->next;
        }
        if (!result) {
            return NULL;
        }
        ListNode* current = result->next;
        ListNode* tmp = result;
        while (current) {
            if (current->val != val) {
                tmp->next = current;
                tmp = tmp->next;
            }
            current = current->next;
        }
        tmp->next = NULL;
        return result;
    }
};