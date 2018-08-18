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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // l1 == NULL   ->   !l1
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode *head = new ListNode(0);
        ListNode *origin = head;
        ListNode *nl1 = l1;
        ListNode *nl2 = l2;
        while (nl1 && nl2) {
            if (nl1 -> val < nl2 -> val) {
                head -> next = nl1;
                head = head -> next;
                nl1 = nl1 -> next;
            } else {
                head -> next = nl2;
                head = head -> next;
                nl2 = nl2 -> next;
            }
        }
        if (nl1) {
            head -> next = nl1;
        }
        if (nl2) {
            head -> next = nl2;
        }
        return origin -> next;
    }
};