class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // if n(1<=num<=k) > k, then 1<=result<=k
        // notice: You must not modify the array (assume the array is read only). You must use only constant, O(1) extra space.
        int low = 1;
        int high = nums.size() - 1;
        int middle;
        int count;
        while (low != high) {
            middle = low + (high - low) / 2; //防止超过int
            count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= middle) count++;
            }
            if (count > middle) high = middle;
            else low = middle + 1;
        }
        return low;
    }
};