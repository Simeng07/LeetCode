class Solution {
public:
    int nthUglyNumber(int n) {
        // 2 4 6 8 10 12 16 18 (no 14)
        // 3 6 9 12 15 18 24 27 (no 21)
        // 5 10 15 20 25 30 40 45 (no 35)
        int ugly[n];
        int numFor2 = 2;
        int numFor3 = 3;
        int numFor5 = 5;
        int indexFor2 = 0;
        int indexFor3 = 0;
        int indexFor5 = 0;
        ugly[0] = 1;
        for (int i = 1; i < n; i++) {
            ugly[i] = min(min(numFor2, numFor3), numFor5);
            // ++indexFor2
            if (ugly[i] == numFor2) numFor2 = 2 * ugly[++indexFor2];
            if (ugly[i] == numFor3) numFor3 = 3 * ugly[++indexFor3];
            if (ugly[i] == numFor5) numFor5 = 5 * ugly[++indexFor5];
        }
        return ugly[n - 1];
    }
};