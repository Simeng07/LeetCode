class Solution {
    // 把 multiset 改成 priority_queue 会快很多
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> v(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            v[i][0] = efficiency[i];
            v[i][1] = speed[i];
        }
        sort(v.begin(), v.end(), [](const vector<int> &v1, const vector<int> &v2){
            return v1[0] > v2[0];
        });
        
        multiset<int> s;
        
        long long ef = 0;
        long long sp = 0;
        long long result = 0;
        for (int i = 0; i < k; i++) {
            s.insert(v[i][1]);
            sp += v[i][1];
            ef = v[i][0];
            result = max(result, sp * ef);
        }
        for (int i = k; i < n; i++) {
            s.insert(v[i][1]);
            sp += v[i][1];
            auto it = s.begin();
            sp -= *it;
            s.erase(it);
            ef = v[i][0];
            result = max(result, sp * ef);
        }
        
        return result % 1000000007;
    }
};