class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        // low is valid; high is invalid
        int low = 1;
        int high = (position[position.size() - 1] - position[0]) / (m - 1);
        if (isValid(position, m, high)) {
            return high;
        }
        int middle = (low + high) / 2;
        while (low < middle) {
            if (isValid(position, m, middle)) {
                low = middle;
            } else {
                high = middle;
            }
            middle = (low + high) / 2;
        }
        return low;
    }
    
    bool isValid(vector<int>& position, int m, int d) {
        int lastIndex = 0;
        int count = 1;
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - position[lastIndex] >= d) {
                lastIndex = i;
                count++;
                if (count == m) {
                    return true;
                }
            }
        }
        return false;
    }
};