class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        if (left.size() > 0) {
            result = *max_element(left.begin(),left.end());
        }
        if (right.size() > 0) {
            result = max(result, n - *min_element(right.begin(),right.end()));
        }
        return result;
    }
};