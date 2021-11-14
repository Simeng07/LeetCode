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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return head;
        }
        int count = 0;
        ListNode* tmp = head;
        while (tmp) {
            count++;
            tmp = tmp->next;
        }
        vector<int> nums(count, 0);
        int index = 0;
        tmp = head;
        while (tmp) {
            nums[index] = tmp->val;
            tmp = tmp->next;
            index++;
        }
        int batch = 1;
        int current = 0;
        bool flag = true;
        while (flag) {
            if (current + batch > count) {
                batch = count - current;
                flag = false;
            }
            if (batch % 2 == 0) {
                reverse(nums.begin() + current, nums.begin() + current + batch);
            }
            current += batch;
            batch++;
        }
        tmp = head;
        for (int i = 0; i < count; i++) {
            tmp->val = nums[i];
            tmp = tmp->next;
        }
        return head;
    }
};