class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        if (nums.size() == 3) return max(max(nums[0], nums[1]), nums[2]);
        
        int a = nums[0];
	    int b = nums[0];
	    int result = 0;
	    for (int i = 2; i < nums.size() - 1; i++) {
            result = max(a + nums[i], b);
            a = b;
            b = result;
	    }
        int result1 = result;
        
        a = nums[1];
	    b = max(nums[1], nums[2]);
	    result = 0;
	    for (int i = 3; i < nums.size(); i++) {
            result = max(a + nums[i], b);
            a = b;
            b = result;
	    }
        int result2 = result;
        
        return max(result1, result2);
    }
};