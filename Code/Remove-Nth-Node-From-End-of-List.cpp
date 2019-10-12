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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        for (int i = 0; i < n; i++) {
            if (!p1) {
                return head;
            }
            p1 = p1->next;
        }
        if (!p1) {
            return head->next;
        }
        while (p1->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *tmp = p2->next;
        p2->next = tmp->next;
        return head;
    }
};