class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (true) {
            int count = 0;
            while (n > 0) {
                int remain = n % 10;
                count += remain * remain;
                n /= 10;
            }
            n = count;
            if (n == 1) {
                return true;
            }
            if (s.count(n)) {
                return false;
            }
            s.insert(n);
        }
    }
};