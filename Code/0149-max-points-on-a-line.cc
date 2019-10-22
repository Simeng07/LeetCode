class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2) {
            return points.size();
        }
        
        unordered_map<long double, int> m;
        int duplicate, vertical, maxp = 0, tmpmaxp;
        long double k;
        
        for (int i = 0; i < points.size() - 1; i++) {
            duplicate = 0;
            vertical = 0;
            tmpmaxp = 0;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i][0] == points[j][0]) {
                    if (points[i][1] == points[j][1]) {
                        duplicate++;
                    } else {
                        vertical++;
                    }
                } else {
                    k = ((long double)(points[i][1] - points[j][1])) / (points[i][0] - points[j][0]);
                    m[k]++;
                    if (tmpmaxp < m[k]) tmpmaxp = m[k];
                }
                if (tmpmaxp < vertical) tmpmaxp = vertical;
            }
            m.clear();
            if (maxp < tmpmaxp + duplicate) maxp = tmpmaxp + duplicate;
        }
        // the point itself
        return maxp + 1;
    }
};