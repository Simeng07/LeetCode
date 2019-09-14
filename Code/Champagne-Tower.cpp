class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        double *glasses = new double[query_row + 1]{0};
        glasses[0] = poured;
        
        for (int i = 1; i <= query_row; i++) {
            for (int j = i; j >= 0; j--) {
                if (j == 0) {
                    glasses[j] = max(0.0, (glasses[0] - 1) / 2);
                } else {
                    glasses[j] = max(0.0, (glasses[j] - 1) / 2) + max(0.0, (glasses[j - 1] - 1) / 2);
                }
            }
        }
        
        double result = min(glasses[query_glass], 1.0);
        delete[] glasses;
        return result;
    }
};