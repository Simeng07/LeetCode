/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
    unordered_map<Node*, Node*> m;
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        }
        if (m.find(head) != m.end()) {
            return m[head];
        }
        Node *result = new Node(head->val);
        m[head] = result;
        result->next = copyRandomList(head->next);
        result->random = copyRandomList(head->random);
        return result;
    }
};