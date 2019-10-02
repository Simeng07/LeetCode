class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if (A.size() <= 1) {
            return A.size();
        }
        int result = 1;
        int start = 0;
        int status = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] < A[i - 1]) {
                if (status == 1) {
                    // do nothing
                } else if (status == -1) {
                    result = max(result, i - start);
                    start = i - 1;
                } else {
                    start = i - 1;
                }
                status = -1;
            } else if (A[i] > A[i - 1]) {
                if (status == -1) {
                    // do nothing
                } else if (status == 1) {
                    result = max(result, i - start);
                    start = i - 1;
                } else {
                    start = i - 1;
                }
                status = 1;
            } else {
                result = max(result, i - start);
                start = i;
                status = 0;
            }
        }
        result = max(result, (int)A.size() - start);
        return result;
    }
};