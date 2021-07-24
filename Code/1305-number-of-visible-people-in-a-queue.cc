class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> result(n, 0);
        set<int> s;
        for (int i = n - 1; i >= 0; i--) {
            if (s.empty()) {
                s.insert(heights[i]);
                continue;
            }
            if (heights[i] <= *s.begin()) {
                result[i] = 1;
            } else {
                int count = 0;
                auto it = s.begin();
                while (it != s.end()) {
                    if (heights[i] > *it) {
                        s.erase(it);
                        ++it;
                        ++count;
                    } else {
                        break;
                    }
                }
                if (!s.empty()) {
                    ++count;
                }
                result[i] = count;
            }
            s.insert(heights[i]);
        }
        return result;
    }
};