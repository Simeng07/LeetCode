class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int size = A.size();
        int notChange = 0, change = 1, tmpNotChange, tmpChange;
        
        for (int i = 1; i < size; i++) {
            tmpNotChange = size;
            tmpChange = size;
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                tmpNotChange = min(tmpNotChange, notChange);
                tmpChange = min(tmpChange, change + 1);
            }
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                tmpNotChange = min(tmpNotChange, change);
                tmpChange = min(tmpChange, notChange + 1);
            }
            notChange = tmpNotChange;
            change = tmpChange;
        }
        return min(change, notChange);
    }
};