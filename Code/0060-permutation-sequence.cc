class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            v.push_back(i);
        }
        return f(v, n, k);
    }
    
    int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }
    
    string f(vector<int>& v, int n, int k) {
        if (n == 1) return to_string(v[0]);
        int fact = factorial(n - 1);
        string d = to_string(v[(k-1)/fact]);
        // delete
        v.erase(v.begin() + (k-1)/fact);
        return d + f(v, n-1, (k%fact == 0) ? fact : (k%fact));
    }
};