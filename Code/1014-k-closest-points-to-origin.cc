class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if (points.size() == K) {
            return points;
        }
        unordered_map<int, unordered_set<int>> m;
        vector<int> heap;
        for (int i = 0; i < points.size(); i++) {
            int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            heap.push_back(dis);
            m[dis].insert(i);
            if (i == K - 1) {
                make_heap(heap.begin(), heap.end());
            }
            if (i >= K) {
                push_heap(heap.begin(), heap.end());
                pop_heap(heap.begin(), heap.end());
                heap.pop_back();
            }
        }
        sort(heap.begin(), heap.end());
        vector<vector<int>> result;
        for (int i = 0; i < heap.size(); i++) {
            if (i == 0 || heap[i] != heap[i - 1]) {
                for (auto index : m[heap[i]]) {
                    result.push_back(points[index]);
                }
            }
        }
        return result;
    }
};