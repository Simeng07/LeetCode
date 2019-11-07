class Solution {
    // 1和3其实可以合起来的...
    string nums1[9] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string nums2[9] = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string nums3[9] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string nums4[4] = {"", " Thousand", " Million", " Billion"};
    
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string result = "";
        int part;
        for (int i = 0; i < 4; i++) {
            if (num == 0) return result;
            part = num % 1000;
            string tmp = helper(part);
            if (tmp != "") {
                if (result == "") result = tmp + nums4[i];
                else result = tmp + nums4[i] + " " + result;
            }
            num /= 1000;
        }
        return result;
    }
    
    string helper(int num) {
        if (num == 0) return "";
        string result = "";
        
        int hundredPart = num / 100;
        if (hundredPart > 0) {
            result = nums1[hundredPart - 1] + " Hundred";
            if (num % 100 > 0) result += " ";
        }
        
        num %= 100;
        if (num == 0) return result;
        if (num < 10) return result + nums1[num - 1];
        if (num == 10) return result + "Ten";
        if (num < 20) return result + nums3[num - 11];
        
        int dig1 = num % 10;
        int dig2 = num / 10;
        if (dig1 == 0) {
            return result + nums2[dig2 - 1];
        } else {
            return result + nums2[dig2 - 1] + " " + nums1[dig1 - 1];
        }
    }
};