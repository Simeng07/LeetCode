class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a = (C - A) * (D - B);
        int b = (G - E) * (H - F);
        int c = (l(A, C, E, G) * l(B, D, F, H));
        return a - c + b;
    }
    
    int l(int a, int b, int c, int d) {
        if (b <= c || d <= a) return 0;
        if (a <= c && b <= d) return b - c;
        if (c <= a && d <= b) return d - a;
        if (c <= a && b <= d) return b - a;
        if (a <= c && d <= b) return d - c;
        return 0;
    }
};