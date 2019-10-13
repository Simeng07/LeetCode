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
    // devide and conquer
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
    
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        if (start + 1 == end) {
            return mergeTwoLists(lists[start], lists[end]);
        }
        ListNode* l1 = mergeKListsHelper(lists, start, (start + end) / 2);
        ListNode* l2 = mergeKListsHelper(lists, (start + end) / 2 + 1, end);
        return mergeTwoLists(l1, l2);
    }
    
    // This is copied from #21 Merge Two Sorted Lists.
    // Not the optimal solution.
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