class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        map<int, int> left, right;
        sort(events.begin(), events.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        int current = 0;
        for (int i = 0; i < events.size(); i++) {
            left[events[i][1]] = max(current, events[i][2]);
            current = left[events[i][1]];
        }
        sort(events.begin(), events.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        current = 0;
        for (int i = events.size() - 1; i >= 0; i--) {
            right[events[i][0]] = max(current, events[i][2]);
            current = right[events[i][0]];
        }
        int result = 0;
        auto it1 = left.begin();
        auto it2 = right.begin();
        while (it2 != right.end() && it2->first <= it1->first) {
            ++it2;
        }
        while (it1 != left.end()) {
            if (it2 != right.end()) {
                result = max(result, it1->second + it2->second);
            } else {
                result = max(result, it1->second);
            }
            ++it1;
            while (it2 != right.end() && it2->first <= it1->first) {
                ++it2;
            }
        }
        return result;
    }
};