class Solution {
public:
    string encode(int num) {
        int fac = 1;
        int pow = 1;
        int tmp = 0;
        while (tmp + pow <= num) {
            tmp += pow;
            fac += 1;
            pow <<= 1;
        }
        fac -= 1;
        int remain = num - tmp;
        string result = "";
        for (int i = 0; i < fac; i++) {
            // cout << remain << " "<<(1 << i)<<endl;
            string current = (remain & (1 << i)) ? "1" : "0";
            result = current + result;
        }
        return result;
    }
};