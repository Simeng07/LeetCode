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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *p = head;
        ListNode *q = head->next;
        ListNode *t = q;
        bool flag = true;
        while (q) {
            p->next = q->next;
            q->next = p;
            if (flag) { // pick the head
                head = q;
                flag = false;
            }
            if (!p->next || !p->next->next) return head;
            t = p;
            p = p->next;
            q = p->next;
            t->next = q;
        }
        return head;
    }
}; 