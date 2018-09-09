/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return NULL;
        }
        Node* root = helper(grid, 0, 0, grid.size());
        return root;
    }
    
    Node* helper(vector<vector<int>>& grid, int minY, int minX, int size) {
        Node* result;
        if (size == 1) {
            result = new Node(grid[minY][minX], true, NULL, NULL, NULL, NULL);
            return result;
        }
        
        Node* topLeft = helper(grid, minY, minX, size / 2);
        Node* topRight = helper(grid, minY, minX + size / 2, size / 2);
        Node* bottomLeft = helper(grid, minY + size / 2, minX, size / 2);
        Node* bottomRight = helper(grid,  minY + size / 2, minX + size / 2, size / 2);
        
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf) {
            if (topLeft->val == topRight->val && topLeft->val == bottomLeft->val && topLeft->val == bottomRight->val) {
                result = new Node(topLeft->val, true, NULL, NULL, NULL, NULL);
                return result;
            }
        }
        result = new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
        return result;
    }
};