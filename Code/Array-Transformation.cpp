class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        int size = arr.size();
        if (size <= 2) {
            return arr;
        }
        bool change;
        while (true) {
            change = false;
            int last = arr[0];
            for (int i = 1; i < size - 1; i++) {
                int tmp = last;
                last = arr[i];
                if (tmp < arr[i] && arr[i + 1] < arr[i]) {
                    change = true;
                    arr[i]--;
                }
                if (tmp > arr[i] && arr[i + 1] > arr[i]) {
                    change = true;
                    arr[i]++;
                }
            }
            if (!change) {
                return arr;
            }
        }
        return arr;
    }
};