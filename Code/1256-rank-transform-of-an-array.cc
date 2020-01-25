class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.size() == 0) {
            return arr;
        }
        
        vector<int> tmp = arr;
        sort(tmp.begin(), tmp.end());
        unordered_map<int, int> m;
        m[tmp[0]] = 1;
        int rank = 1;
        
        for (int i = 1; i < tmp.size(); i++) {
            if (tmp[i] == tmp[i - 1]) {
                continue;
            }
            rank++;
            m[tmp[i]] = rank;
        }
        
        vector<int> result;
        for (int i = 0; i < arr.size(); i++) {
            result.push_back(m[arr[i]]);
        }
        
        return result;
    }
};