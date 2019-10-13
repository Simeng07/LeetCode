class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 1. Find the largest index k such that nums[k] < nums[k + 1]. 
        //    If no such index exists, the permutation is sorted in descending order, just reverse it to ascending order and we are done. 
        // 2. Find the largest index l greater than k such that nums[k] < nums[l].
        // 3. Swap the value of nums[k] with that of nums[l].
        // 4. Reverse the sequence from nums[k + 1] up to and including the final element nums[nums.size() - 1].
        
        // or this:
        // void nextPermutation(vector<int>& nums) {
        //     int i;
        //     for(i = nums.size() - 1;i > 0 && nums[i-1] >= nums[i];i--);
        //     std::reverse(nums.begin() + i, nums.end());
        //     if (i>0) swap(nums[i-1],*upper_bound(nums.begin() + i, nums.end(),nums[i-1]));
        // }
        
        int k = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                k = i;
                break;
            }
        }
        if (k == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int l = -1;
        // upper_bound is valid
        for (int i = nums.size() - 1; i > k; i--) {
            if (nums[i] > nums[k]) {
                l = i; 
                break;
            }
        }
        // swap
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
};