class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        sort(arr.begin(), arr.end());
        int tmpMin = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++) {
            tmpMin = min(tmpMin, arr[i] - arr[i - 1]);
        }
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == tmpMin) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }
        return result;
    }
};