class Solution {
public:
    string largestNumber(vector<int> &num) {
        string result = "";
        sort(num.begin(), num.end(), compare);
        for (int i = 0; i < num.size(); i++) {
            result.append(to_string(num[i]));
        }
        
        if (result[0] == '0' && result.size() > 0) {
            return "0";
        }
        return result;
    }
    
    static bool compare(int a, int b) {
        return to_string(a)+to_string(b)>to_string(b)+to_string(a);
    }
};