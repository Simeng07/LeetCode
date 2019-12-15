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
    int getDecimalValue(ListNode* head) {
        int i = 0;
        while (head) {
            i <<= 1;
            i |= head->val;
            head = head->next;
        }
        return i;
    }
};