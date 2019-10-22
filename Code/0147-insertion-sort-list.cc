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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *p = head->next;
        ListNode *q = head->next;
        ListNode *result = head;
        result->next = NULL;
        ListNode *r = result;
        while (p != NULL) {
            q = p;
            p = p->next;
            if (q->val <= result->val) {
                q->next = result;
                result = q;
                continue;
            }
            r = result;
            while ((r->next != NULL) && (q->val > r->next->val)) r = r->next;
            q->next = r->next;
            r->next = q;
        }
        return result;
    }
};