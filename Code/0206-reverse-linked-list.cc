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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* result = head;
        ListNode* current = head->next;
        ListNode* tmp;
        result->next = NULL;
        while (current) {
            tmp = current->next;
            current->next = result;
            result = current;
            current = tmp;
        }
        return result;
    }
};