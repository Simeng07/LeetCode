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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *smallerBegin = nullptr, *smallerEnd = nullptr, *biggerBegin = nullptr, *biggerEnd = nullptr, *current = head, *next = head->next;
        while (current) {
            if (current->val < x) {
                if (!smallerBegin) {
                    smallerBegin = current;
                    smallerEnd = current;
                } else {
                    smallerEnd->next = current;
                    smallerEnd = smallerEnd->next;
                }
            } else {
                if (!biggerBegin) {
                    biggerBegin = current;
                    biggerEnd = current;
                } else {
                    biggerEnd->next = current;
                    biggerEnd = biggerEnd->next;
                }
            }
            current->next = nullptr;
            current = next;
            if (next) {
                next = next->next;
            }
        }
        if (!smallerBegin) {
            return biggerBegin;
        }
        if (!biggerBegin) {
            return smallerBegin;
        }
        smallerEnd->next = biggerBegin;
        return smallerBegin;
    }
};