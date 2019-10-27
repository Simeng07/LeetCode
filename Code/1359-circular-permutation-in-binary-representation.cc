class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> tmp = helper(n, start);
        // vector<int> result;
        // int i;
        // for (int i = 0; i < tmp.size(); i++) {
        //     if (tmp[i] == start) {
        //         break;
        //     }
        // }
        // result.insert(result.end(), tmp.begin() + (i - 1), tmp.end());
        // result.insert(result.end(), tmp.begin(), tmp.begin() + i);
        return tmp;
    }
    
    vector<int> helper(int n, int start) {
        if (n == 1) {
            return {start, start ^ 1};
        }
        vector<int> result;
        int leftmost = 1 << (n - 1);
        if (start & leftmost) {
            vector<int> tmp = helper(n - 1, start - leftmost);
            for (int i = 0; i < tmp.size(); i++) {
                result.push_back(tmp[i] | leftmost);
            }
            for (int i = tmp.size() - 1; i >= 0; i--) {
                result.push_back(tmp[i]);
            }
        } else {
            result = helper(n - 1, start);
            for (int i = result.size() - 1; i >= 0; i--) {
                result.push_back(result[i] | leftmost);
            }
        }
        return result;
    }
};