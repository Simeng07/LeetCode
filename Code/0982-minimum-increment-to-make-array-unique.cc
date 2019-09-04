class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.size() < 2) {
            return 0;
        }
        
        int count[40000];
        memset(count, 0, sizeof(count));
        int maxValue = A[0];
        int minValue = A[0];
        for (auto a : A) {
            count[a]++;
            maxValue = max(maxValue, a);
            minValue = min(minValue, a);
        }
        
        int result = 0;
        int currentShouldBe = minValue;
        
        for (int i = minValue; i <= maxValue; i++) {
            if (count[i] != 0) {
                result += count[i] * (count[i] - 1) / 2;
                if (currentShouldBe <= i) {
                    currentShouldBe = i + count[i];
                } else {
                    result += (currentShouldBe - i) * count[i];
                    currentShouldBe = currentShouldBe + count[i];
                }
            }
        }
        
        
        return result;
    }
};