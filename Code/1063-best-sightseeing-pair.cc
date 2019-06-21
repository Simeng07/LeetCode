class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int result = A[0] + A[1] - 1;
        int tmpi = 0;

        for (int i = 1; i < A.size(); i++) {
            result = max(result, A[tmpi] + tmpi + A[i] - i);
            if (A[tmpi] + tmpi <= A[i] + i) {
                tmpi = i;
            }
        }

        return result;
    }
};