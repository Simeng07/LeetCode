class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) {
            return 0;
        }
        
        unordered_map<int, unordered_set<int> > m;
        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            if (m.find(x) != m.end()) {
                m[x].insert(y);
            } else {
                m[x] = {y};
            }
        }
        
        bool found = false;
        int tmpMin = 1600000000;
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                if (x1 == x2 || y1 == y2) {
                    continue;
                }
                
                if (m[x1].find(y2) != m[x1].end() && m[x2].find(y1) != m[x1].end()) {
                    tmpMin = min(tmpMin, abs((x2 - x1) * (y2 - y1)));
                    found = true;
                }
            }
        }
        
        return (found ? tmpMin : 0);
    }
};