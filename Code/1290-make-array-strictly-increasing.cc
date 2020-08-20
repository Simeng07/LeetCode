class Solution {
    unordered_map<int, unordered_map<int, int>> m;
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        set<int> s(arr2.begin(), arr2.end());
        arr2.clear();
        arr2.insert(arr2.begin(), s.begin(), s.end());
        int result = helper(arr1, arr2, 0, -1, -1);
        if (result > arr1.size()) {
            result = -1;
        }
        return result;
    }
    
    int helper(vector<int>& arr1, vector<int>& arr2, int index, int lastNum, int lastNumIndexInArr2) {
        if (m.find(index) != m.end() && m[index].find(lastNum) != m[index].end()) {
            return m[index][lastNum];
        }
        if (index >= arr1.size()) {
            return 0;
        }
        int minChange = arr1.size() + 1;
        if (arr1[index] > lastNum) {
            minChange = helper(arr1, arr2, index + 1, arr1[index], -1);
        }
        if (lastNumIndexInArr2 != -1 && lastNumIndexInArr2 != arr2.size() - 1) {
            minChange = min(minChange, 1 + helper(arr1, arr2, index + 1, arr2[lastNumIndexInArr2 + 1], lastNumIndexInArr2 + 1));
        } else {
            auto it = upper_bound(arr2.begin(), arr2.end(), lastNum);
            if (it != arr2.end()) {
                minChange = min(minChange, 1 + helper(arr1, arr2, index + 1, *it, it - arr2.begin()));
            }
        }
        m[index][lastNum] = minChange;
        // cout << index << " " << lastNum << " " << minChange << endl;
        return m[index][lastNum];
    }
};