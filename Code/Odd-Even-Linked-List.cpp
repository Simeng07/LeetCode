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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;
        ListNode* odd = head;
        ListNode* evenOrigin = head->next;
        ListNode* even = head->next;
        while (1) {
            if (even->next != NULL) {
                odd->next = even->next;
                odd = odd->next;
            } else {
                odd->next = evenOrigin;
                even->next = NULL;
                return head;
            }
            if (odd->next != NULL) {
                even->next = odd->next;
                even = even->next;
            } else {
                odd->next = evenOrigin;
                even->next = NULL;
                return head;
            }
        }
    }
};