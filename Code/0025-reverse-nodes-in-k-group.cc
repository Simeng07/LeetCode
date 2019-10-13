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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k <= 1) return head;
        // pay attention to 1 and 7 when rotate 23456 in 1234567. 1->next=6，2->next=7
        ListNode *current, *before, *after; // notice. how to declare multiple pointers
        int count = 0;
        current = after = head;
        before = NULL;
        
        while(after) {
            count++;
            after = after->next;
            if (count == k) {
                ListNode *first, *following;
                first = current;
                while (count-- > 1) {
                    following = current->next;
                    current->next = following->next;
                    following->next = first;
                    first = following;
                }
                
                if (before) {
                    before->next = first;
                } else {
                    head = first; // the very first one
                }
                 
                before = current;
                current = after;
                count = 0;
            }
        }
        
        return head;
    }
};