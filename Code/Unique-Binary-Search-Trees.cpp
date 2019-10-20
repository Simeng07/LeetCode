class Solution {
public:
    int numTrees(int n) {
        vector<int> v; // method count with i nodes
        v.push_back(1); // v[0], no node at one side
        for (int i = 1; i <= n; i++) {
            v.push_back(0);
            for (int j = 1; j <= i; j++) {
                // eg，i=7，j=5，left 1234（5-1），right 67（7-5）
                v[i] += v[j - 1] * v[i - j];
            }
        }
        return v[n];
    }
};