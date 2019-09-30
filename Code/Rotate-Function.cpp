class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int size = A.size();
        if (size == 0) {
            return 0;
        }
        long long once = 0, result = 0;
        for (int i = 0; i < size; i++) {
            once += A[i];
            result += i * A[i];
        }
        long long last = result;
        for (int i = 1; i < size; i++) {
            last = last + once - (long long)A[size - i] * size;
            result = max(result, last);
        }
        return result;
    }
};