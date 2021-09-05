class Solution {
    int maxNum;
    int root[100001];
    int spf[100001];
public:
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        maxNum = sorted[n - 1];
        getSmallestPrimeFactor();
        for (int i = 0; i < maxNum; i++) {
            root[i] = i;
        }
        for (int i = 0; i < n; i++) {
            root[sorted[i]] = sorted[i];
            auto s = getFactors(sorted[i]);
            for (auto it = s.begin(); it != s.end(); ++it) {
                int r = findRoot(*it);
                root[r] = root[sorted[i]];
            }
        }
        for (int i = 0; i < n; i++) {
            if (findRoot(nums[i]) != findRoot(sorted[i])) {
                return false;
            }
        }
        return true;
    }
    
    int findRoot(int num) {
        int tmpNum = num;
        while (tmpNum != root[tmpNum]) {
            tmpNum = root[tmpNum];
        }
        root[num] = tmpNum;
        return tmpNum;
    }
    
    void getSmallestPrimeFactor() {
        for (int i = 1; i <= maxNum; i++) {
            spf[i] = i;
        }
        for (int i = 2; i * i <= maxNum; i++) {
            if (spf[i] != i) {
                continue;
            }
            for (int j = i * i; j <= maxNum; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    
    unordered_set<int> getFactors(int num) {
        unordered_set<int> factors;
        while (num > 1) {
            factors.insert(spf[num]);
            num /= spf[num];
        }
        return factors;
    }
};