class Solution {
public:
    int romanToInt(string s) {
        // // 声明方法
        // unordered_map<char, int> T = { { 'I' , 1 },
        //                                { 'V' , 5 },
        //                                { 'X' , 10 },
        //                                { 'L' , 50 },
        //                                { 'C' , 100 },
        //                                { 'D' , 500 },
        //                                { 'M' , 1000 } };
        unordered_map<char, int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        int result = 0;
        int n = s.length();
        result += map[s[n - 1]];
        for (int i = n - 2; i >= 0; i--) {
            if (map[s[i]] >= map[s[i + 1]]) {
                result += map[s[i]];
            } else {
                result -= map[s[i]];
            }
        }
        
        return result;
    }
};