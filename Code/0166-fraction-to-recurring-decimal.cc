class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long Numerator = numerator;
        long long Denominator = denominator;

        ostringstream out;
    
        if (Denominator < 0) {
            Numerator *= -1;
            Denominator *= -1;
        }
    
        if (Numerator < 0) {
            Numerator *= -1;
            out << "-";
        }
    
        out << Numerator / Denominator;
    
        if (Numerator % Denominator == 0) {
            return out.str();
        }
    
        out << ".";
    
        long long rem = Numerator % Denominator;
        vector<int> v;
        map<int, int> m;
    
        int i = 0;
        while (m.find(rem) == m.end() && rem != 0) {
            m[rem] = i;
            rem *= 10;
            v.push_back(rem / Denominator);
            rem = rem % Denominator;
            i++;
        }
    
        if (rem == 0) {
            for (int i = 0; i < v.size(); i++) {
                out << v[i];
            }
        } else {
            for (int i = 0; i < m[rem]; i++) {
                out << v[i];
            }
            out << "(";
            for (int i = m[rem]; i < v.size(); i++) {
                out << v[i];
            }
            out << ")";
        }
    
        return out.str();
    }
};