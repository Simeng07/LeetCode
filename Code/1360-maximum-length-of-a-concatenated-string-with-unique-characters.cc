class Solution {
    string result[131072];
public:
    int maxLength(vector<string>& arr) {
        if (arr.size() == 0) {
            return 0;
        }
        if (arr.size() == 1) {
            if (checkself(arr[0])) {
                return arr[0].length();
            } else {
                return 0;
            }
        }
        long long leftmost = 1;
        int index = 0;
        result[0] = "";
        if (checkself(arr[0])) {
            result[1] = arr[0];
        } else {
            result[1] = "A";
        }
        
        long long mostb = pow(2, arr.size() + 1);
        for (long long  i = 2; i < mostb; i++) {
            if ((leftmost << 1) <= i) {
                leftmost <<= 1;
                index++;
            }
            result[i] = makea(arr, i - leftmost, index - 1);
            // cout << i << " " << result[i] << endl;
        }
        int ans = 0;
        for (int i = 0; i < mostb; i++) {
            if (result[i] != "A") {
                ans = max(ans, (int)(result[i]).length());
            }
        }
        return ans;
    }
    
    string makea(vector<string>& arr, int i, int index) {
        string current = arr[index];
        if (!checkself(current)) {
            return "A";
        }
        if (result[i] != "A") {
            if (result[i] == "") {
                return current;
            }
            for (auto &c : current) {
                std::size_t found = result[i].find(c);
                if (found!=std::string::npos) {
                    return "A";
                }
            }
            return result[i]+current;
        } else {
            return "A";
        }
    }
    
    bool checkself(string s) {
        int count[26] = {0};
        for (auto &c : s) {
            count[c-'a']++;
            if (count[c-'a'] > 1) {
                return false;
            }
        }
        return true;
    }
};