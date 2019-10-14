class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int result = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftHeight = height[left];
        int rightHeight = height[right];
        // make sure to move the shorter bar ahead
        while (left < right) {
            if (leftHeight < rightHeight) {
                if (height[left] <= leftHeight) {
                    result += leftHeight - height[left];
                    left++;
                } else {
                    leftHeight = height[left];
                }
            } else {
                if (height[right] <= rightHeight) {
                    result += rightHeight - height[right];
                    right--;
                } else {
                    rightHeight = height[right];
                }
            }
        }
        return result;
    }
};