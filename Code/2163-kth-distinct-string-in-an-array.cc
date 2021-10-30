class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> count;
        for (auto &s : arr) {
            count[s]++;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (count[arr[i]] == 1) {
                k--;
                if (k == 0) {
                    return arr[i];
                }
            }
        }
        return "";
    }
};