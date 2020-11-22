class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        int remain = 0;
        int result = 0;
        for (auto &task : tasks) {
            if (task[1] <= remain) {
                remain -= task[0];
            } else {
                result += (task[1] - remain);
                remain = task[1] - task[0];
            }
        }
        return result;
    }
};