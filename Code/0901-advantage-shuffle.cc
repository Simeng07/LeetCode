class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> s(A.begin(), A.end());
        vector<int> result;
        
        for (auto b : B) {
            auto it = s.upper_bound(b);
            if (it == s.end()) {
                it = s.begin();
            }
            result.push_back(*it);
            s.erase(it);
        }
        
        return result;
    }
};