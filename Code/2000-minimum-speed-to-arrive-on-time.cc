class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (ceil(hour) < dist.size()) {
            return -1;
        }
        int low = 1;
        int high = INT_MAX;
        int middle = low + (high - low) / 2;
        while (low < middle) {
            double time = 0;
            for (int i = 0; i < dist.size() - 1; i++) {
                time += ceil((double)dist[i] / middle);
            }
            time += ((double)dist[dist.size() - 1]) / middle;
            if (time > hour) {
                low = middle;
            } else {
                high = middle;
            }
            middle = (low + high) / 2;
        }
        double time = 0;
        for (int i = 0; i < dist.size() - 1; i++) {
            time += ceil((double)dist[i] / low);
        }
        time += ((double)dist[dist.size() - 1]) / low;
        if (time > hour) {
            return high;
        }
        return low;
    }
};