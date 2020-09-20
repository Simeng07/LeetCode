class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int begins[100000] = {0};
        int ends[100000] = {0};
        int maxIndex = 0;
        for (auto &request : requests) {
            begins[request[0]]++;
            ends[request[1] + 1]++;
            maxIndex = max(maxIndex, request[1]);
        }
        
        int currentCount = 0;
        vector<int> countCount(requests.size() + 1, 0);
        for (int i = 0; i <= maxIndex; i++) {
            currentCount += begins[i];
            currentCount -= ends[i];
            countCount[currentCount]++;
        }
        
        sort(nums.begin(), nums.end(), greater<int>());
        int numIndex = 0;
        
        long long result = 0;
        for (int i = countCount.size() - 1; i > 0; i--) {
            if (countCount[i] == 0) {
                continue;
            }
            long long totalNum = 0;
            for (int j = 0; j < countCount[i]; j++) {
                totalNum += nums[numIndex++];
            }
            totalNum %= 1000000007;
            result += totalNum * i;
            result %= 1000000007;
        }
        
        return (int)result;
    }
};