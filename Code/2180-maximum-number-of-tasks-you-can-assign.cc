class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int low = 0, high = min(m, n);
        int result = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            bool flag = true;
            multiset<int> s(workers.begin(), workers.end());
            for (int i = mid - 1; i >= 0; i--) {
                auto it = s.end();
                --it;
                if (tasks[i] <= *it) {
                    s.erase(it);
                } else {
                    it = s.lower_bound(tasks[i] - strength);
                    if (it != s.end()) {
                        count++;
                        if (count > pills) {
                            flag = false;
                            break;
                        }
                        s.erase(it);
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};