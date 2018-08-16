class Solution {
public:
//     // 另一种思路：
//     string intToRoman(int num) 
//     {
//         string res = "";
//         vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
//         vector<string> s{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
//         for (int i = 0; i < val.size(); i++)
//         {
//             while (num >= val[i])
//             {
//                 num -= val[i];
//                 res += s[i];
//             }
//         }       
//         return res;       
//     }
    
    string intToRoman(int num) { 
        string result = "";
        int ones = num % 10;
        int tens = (num / 10) % 10;
        int hundreds = (num / 100) % 10;
        int thousands = (num / 1000) % 10;
        for (int i = 0; i < thousands; i++) {
            result += "M";
        }
        
        if (hundreds == 9) {
            result += "CM";
        } else if (hundreds == 4) {
            result += "CD";
        } else if (hundreds >= 5) {
            result += "D";
            for (int i = 0; i < hundreds - 5; i++) {
                result += "C";
            }
        } else {
            for (int i = 0; i < hundreds; i++) {
                result += "C";
            }
        }
        
        if (tens == 9) {
            result += "XC";
        } else if (tens == 4) {
            result += "XL";
        } else if (tens >= 5) {
            result += "L";
            for (int i = 0; i < tens - 5; i++) {
                result += "X";
            }
        } else {
            for (int i = 0; i < tens; i++) {
                result += "X";
            }
        }
        
        if (ones == 9) {
            result += "IX";
        } else if (ones == 4) {
            result += "IV";
        } else if (ones >= 5) {
            result += "V";
            for (int i = 0; i < ones - 5; i++) {
                result += "I";
            }
        } else {
            for (int i = 0; i < ones; i++) {
                result += "I";
            }
        }
        
        return result;
    }
};