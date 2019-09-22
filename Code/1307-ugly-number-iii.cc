class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        if (!(a <= b && b <= c)) {
            return nthUglyNumber(n, min(min(a, b), c), a + b + c - min(min(a, b), c) - max(max(a, b), c), max(max(a, b), c));
        }
        cout << a << " " << b << " " << c << endl;
        int result = 0;
        long tmpa = a, tmpb = b, tmpc = c;
        int minmul = b / a;
        if (minmul >= n) {
            return a * n;
        } else {
            tmpa = a * (b / a);
        }
        for (int i = minmul; i < n; i++) {
            result = min(min(tmpa, tmpb), tmpc);
            if (result == tmpa) {
                int next = min(tmpb, tmpc);
                int counta = (next - tmpa) / a;
                if (counta > 1) {
                    if (counta < n - i) {
                        i += (counta - 1);
                        tmpa += a * counta;
                    } else {
                        return tmpa + a * (n - i);
                    }
                } else {
                    tmpa += a;
                }
            }
            if (result == tmpb) {
                tmpb += b;
            }
            if (result == tmpc) {
                tmpc += c;
            }
        }
        result = min(min(tmpa, tmpb), tmpc);
        return result;
    }
};