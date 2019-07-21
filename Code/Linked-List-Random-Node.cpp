/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *headNode;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        headNode = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        // ReadMe:
        // 本题解法有2，重点关注高级的【Reservoir Sampling(水塘抽样)】算法。
        // “水塘抽样是一系列的随机算法，其目的在于从包含n个项目的集合S中选取k个样本，其中n为一很大或未知的数量，尤其适用于不能把所有n个项目都存放到内存的情况”
        // https://zh.wikipedia.org/wiki/%E6%B0%B4%E5%A1%98%E6%8A%BD%E6%A8%A3
        // 另一种是遍历一遍找到length，然后rand()%length取出index；再遍历链表返回index节点的值。方法比较low，leetcode可过，但不推荐
        int result = headNode -> val;
        ListNode *current = headNode;
        ListNode *pick = headNode;
        int index = 1;
        
        while (current->next) {
            current = current->next;
            index++;
            int k = rand() % index;
            if (k == 0) {   // （1 / index）的概率被选中
                pick = current;
            }
        }
        
        return pick->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */