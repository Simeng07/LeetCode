class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > result;
        if (n == 0 || k == 0) return result;
        vector<int> v;
        helper(result, v, n, k, 1);
        return result;
    }
    
    // backtracking
    void helper(vector<vector<int> >& result, vector<int>& v, int n, int k, int start) {
        if (k == 0) {
            result.push_back(v);
            return;
        }
        for (int i = start; i <= n - k + 1; i++) {
            v.push_back(i);
            helper(result, v, n, k - 1, i + 1);
            v.pop_back();
        }
    }
};