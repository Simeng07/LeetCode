class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        if (events.size() == 1) {
            return 1;
        }
        
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int index = 0, result = 0;
        
        for (int d = 1; d <= 100000; d++) {
            while (index < events.size() && events[index][0] == d) {
                // start at date d. record the end date
                pq.push(events[index][1]);
                index++;
            }
            while (!pq.empty() && pq.top() < d) {
                // clear the meeting that has ended
                pq.pop();
            }
            if (!pq.empty()) {
                result++;
                pq.pop();
            }
        }
        
        return result;
    }
};