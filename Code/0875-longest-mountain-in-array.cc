class Solution {
public:
    int longestMountain(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        int result = 0;
        int start = -1;
        int status = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i - 1]) {
                if (status == -1) {
                    if (start != -1) {
                        result = max(result, i - start);
                    }
                    start = i - 1;
                } else if (status == 0) {
                    start = i - 1;
                }
                status = 1;
            } else if (A[i] < A[i - 1]) {
                status = -1;
            } else {
                if (status == -1) {
                    if (start != -1) {
                        result = max(result, i - start);
                    }
                }
                status = 0;
                start = -1;
            }
        }
        if (status == -1 && start != -1) {
            result = max(result, (int)A.size() - start);
        }

        return result;
    }
};