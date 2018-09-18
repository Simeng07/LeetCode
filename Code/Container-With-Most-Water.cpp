class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int p = 0, q = height.size() - 1;
        while (p != q) {
            result = max(result, (q - p) * min(height[q], height[p]));
            if (height[p] < height[q]) {
                p++;
            } else {
                q--;
            }
        }
        return result;
    }
};