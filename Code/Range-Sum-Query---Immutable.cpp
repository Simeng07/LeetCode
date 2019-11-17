class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        sums = vector<int> (n + 1);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
    
    // sums = vector<int> (n + 1);
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */