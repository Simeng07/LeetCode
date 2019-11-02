class Solution {
public:
    // 改进的快排
    // int findKthLargest(vector<int>& nums, int k) {
    //     return helper(nums, k, 0, nums.size() - 1);
    // }
    // int helper(vector<int>& nums, int k, int p, int q) {
    //     int tmp = nums[p];
    //     int r = p + 1, s = q;
    //     while (r <= s) {
    //         while (nums[r] <= tmp) r++;
    //         while (nums[s] > tmp) s--;
    //         if (r <= s) {
    //             swap(nums[r], nums[s]);
    //             r++;
    //             s--;
    //         }
    //     }
    //     if (q - s == k - 1) return tmp;
    //     else if (q - s > k - 1) return helper(nums, k, s + 1, q);
    //     else return helper(nums, k - (q - s) - 1, p + 1, r - 1);
    // }
    
    
    int findKthLargest(vector<int>& nums, int k) {
        //max heap method
        //min heap method
        //order statistics
        make_heap(nums.begin(), nums.end());
        int result;
        for(int i=0; i<k; i++){
            result=nums.front();
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return result;
    }
};