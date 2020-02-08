class Solution {
public:
    int minJumps(vector<int>& arr) {
        int jumps[50000];
        unordered_map<int, unordered_set<int>> m;
        unordered_set<int> forbid;
        int size = arr.size();
        if (size == 1) {
            return 0;
        }
        if (arr[0] == arr[size - 1]) {
            return 1;
        }
        jumps[0] = 0;
        for (int i = 1; i < size; i++) {
            jumps[i] = -1;
            if (i == size - 1 || arr[i] != arr[i - 1] || arr[i] != arr[i + 1]) {
                m[arr[i]].insert(i);
            } else {
                forbid.insert(i);
            }
        }
        int result = 1;
        unordered_set<int> current;
        unordered_set<int> next;
        current.insert(0);
        while (!current.empty()) {
            for (auto it = current.begin(); it != current.end(); ++it) {
                int index = *it;
                if (index - 1 >= 0 && jumps[index - 1] == -1 && forbid.find(index - 1) == forbid.end()) {
                    jumps[index - 1] = result;
                    next.insert(index - 1);
                }
                if (index + 1 == size - 1) {
                    return result;
                }
                if (index + 1 < size - 1 && jumps[index + 1] == -1 && forbid.find(index + 1) == forbid.end()) {
                    jumps[index + 1] = result;
                    next.insert(index + 1);
                }
                for (auto it2 = m[arr[index]].begin(); it2 != m[arr[index]].end(); ++it2) {
                    if (*it2 == size - 1) {
                        return result;
                    }
                    if (jumps[*it2] == -1) {
                        jumps[*it2] = result;
                        next.insert(*it2);
                    }
                }
            }
            current = next;
            next.clear();
            result++;
        }
        return result;
    }
};