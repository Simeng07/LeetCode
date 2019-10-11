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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *result = head;
        int carry = 0;
        while (l1 || l2) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            int digit = sum % 10;
            carry = sum / 10;
            ListNode *node = new ListNode(digit);
            head->next = node;
            head = head->next;
        }
        if (carry != 0) {
            ListNode *node = new ListNode(carry);
            head->next = node;
        }
        return result->next;
    }
};