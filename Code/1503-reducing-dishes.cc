class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        auto it = lower_bound(satisfaction.begin(), satisfaction.end(), 0);
        if (it == satisfaction.end()) {
            return 0;
        }
        int index = it - satisfaction.begin();
        int level = 0, total = 0;
        for (int i = index; i < satisfaction.size(); i++) {
            level += satisfaction[i] * (i - index + 1);
            total += satisfaction[i];
        }
        if (index == 0) {
            return level;
        }
        for (int i = index - 1; i >= 0; i--) {
            total += satisfaction[i];
            if (total > 0) {
                level += total;
            } else {
                return level;
            }
        }
        return level;
    }
};