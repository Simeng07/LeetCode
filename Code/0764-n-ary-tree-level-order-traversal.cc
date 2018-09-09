/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > result;
        if (!root) {
            return result;
        }
        vector<Node *> parents;
        parents.push_back(root);
        vector<Node *> children;
        while (parents.size() != 0) {
            vector<int> row;
            for (int i = 0; i < parents.size(); i++) {
                row.push_back(parents[i]->val);
                for (int j = 0; j < parents[i]->children.size(); j++) {
                    children.push_back(parents[i]->children[j]);
                }
            }
            result.push_back(row);
            parents = children;
            children.clear();
        }
        return result;
    }
};