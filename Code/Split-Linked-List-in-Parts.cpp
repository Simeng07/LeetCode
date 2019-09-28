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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        if (k == 1) {
            return {root};
        }
        vector<ListNode*> result;
        ListNode* head = root;
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        int size = count / k;
        int large = count % k;
        head = root;
        for (int j = 0; j < k; j++) {
            result.push_back(head);
            if (head) {
                int num = size + (large-- > 0 ? 1 : 0);
                for (int i = 1; i < num; i++) {
                    head = head->next;
                }
                ListNode* tmp = head;
                head = head->next;
                tmp->next = NULL;
            }
        }
        
        return result;
    }
};