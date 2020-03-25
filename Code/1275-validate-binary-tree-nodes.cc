class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // find the root
        bool has[10000] = {0};
        for (auto child : leftChild) {
            if (child != -1) {
                has[child] = true;
            }
        }
        for (auto child : rightChild) {
            if (child != -1) {
                has[child] = true;
            }
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (!has[i]) {
                if (root != -1) {
                    // multiple roots
                    return false;
                }
                root = i;
            }
        }
        if (root == -1) {
            // no root
            return false;
        }
        
        memset(has, false, sizeof(bool) * n);
        has[root] = true;
        
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            int left = leftChild[front];
            if (left != -1) {
                if (has[left]) {
                    return false;
                }
                has[left] = true;
                q.push(left);
            }
            int right = rightChild[front];
            if (right != -1) {
                if (has[right]) {
                    return false;
                }
                has[right] = true;
                q.push(right);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (!has[i]) {
                return false;
            }
        }
        
        return true;
    }
};