class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<array<double, 3>> pq;
        double result = 0;
        for (auto &cls : classes) {
            if (cls[1] == cls[0]) {
                result += 1.0;
            } else {
                double a = (double)cls[0];
                double b = (double)cls[1];
                pq.push({(a + 1) / (b + 1) - a / b, a, b});
                result += a / b;
            }
        }
        
        while (extraStudents > 0 && !pq.empty()) {
            auto v = pq.top();
            result -= v[1] / v[2];
            int count = 0;
            double a = v[1];
            double b = v[2];
            pq.pop();
            auto v2 = pq.top();
            
            // add count students to v
            while ((a + 1) / (b + 1) - a / b >= v2[0] && count + 1 <= extraStudents) {
                a++;
                b++;
                count++;
            }
            
            result += a / b;
            pq.push({{(a + 1) / (b + 1) - a / b, a, b}});
            extraStudents -= count;
        }
        
        return result / classes.size();
    }
};