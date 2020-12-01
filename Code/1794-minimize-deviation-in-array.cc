class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int maxMin = INT_MIN, minMin = INT_MAX;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto &num : nums) {
            if (num & 1) {
                pq.push({num, num * 2});
            } else {
                int tmpMax = num;
                while (!(num & 1)) {
                    num >>= 1;
                }
                pq.push({num, tmpMax});
            }
            maxMin = max(maxMin, num);
            minMin = min(minMin, num);
        }
        
        int result = maxMin - minMin;
        
        while (!pq.empty()) {
            auto &p = pq.top();
            int currentValue = p.first;
            int currentMax = p.second;
            pq.pop();
            result = min(maxMin - currentValue, result);
            if (2 * currentValue <= currentMax) {
                pq.push({2 * currentValue, currentMax});
                maxMin = max(2 * currentValue, maxMin);
            } else {
                break;
            }
        }
        
        return result;
    }
};