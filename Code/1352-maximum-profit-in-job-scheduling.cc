class Solution {
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int size = startTime.size();
        vector<vector<int>> v(size);
        for (int i = 0; i < size; i++) {
            v[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(v.begin(), v.end());
        
        map<int, int> m;
        for (int i = size - 1; i >= 0; i--) {
            int nextProfit = 0;
            auto it2 = m.lower_bound(v[i][1]);
            if (it2 != m.end()) {
                nextProfit = it2->second;
            }
            if (i == size - 1) {
                m[v[i][0]] = v[i][2];
            } else {
                m[v[i][0]] = max(m[v[i + 1][0]], nextProfit + v[i][2]);
            }
        }
        
        return m[v[0][0]];
    }
};