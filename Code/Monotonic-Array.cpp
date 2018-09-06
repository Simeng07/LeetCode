class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() < 2) {
            return true;
        }
        return checkAsc(A) || checkDsc(A);
    }
    bool checkAsc(vector<int>& A) {
        for (int i = 0; i < A.size() - 1; i++) {
            if (A[i] > A[i + 1]) {
                return false;
            }
        }
        return true;
    }
    bool checkDsc(vector<int>& A) {
        for (int i = 0; i < A.size() - 1; i++) {
            if (A[i] < A[i + 1]) {
                return false;
            }
        }
        return true;
    }
};