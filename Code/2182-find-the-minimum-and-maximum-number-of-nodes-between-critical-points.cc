/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int index = 0;
        int lastValue = head->val;
        int lastCritical = -1;
        head = head->next;
        int minValue = INT_MAX;
        if (!head) {
            return {-1, -1};
        }
        while (head->next) {
            index++;
            int current = head->val;
            head = head->next;
            int next = head->val;
            if ((current > lastValue && current > next) || (current < lastValue && current < next)) {
                if (first == -1) {
                    first = index;
                } else {
                    minValue = min(minValue, index - lastCritical);
                }
                lastCritical= index;
            }
            lastValue = current;
        }
        if (minValue == INT_MAX) {
            return {-1, -1};
        }
        return {minValue, lastCritical - first};
    }
};