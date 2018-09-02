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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return NULL;
        }
        int lengthA = 1, lengthB = 1;
        ListNode *A = headA, *B = headB;
        while (A->next) {
            lengthA++;
            A = A->next;
        }
        while (B->next) {
            lengthB++;
            B = B->next;
        }
        A = headA;
        B = headB;
        for (int i = lengthA; i < lengthB; i++) {
            B = B->next;
        }
        for (int i = lengthB; i < lengthA; i++) {
            A = A->next;
        }
        while (A) {
            if (A == B) {
                return A;
            } else {
                A = A->next;
                B = B->next;
            }
        }
        return NULL;
    }
};