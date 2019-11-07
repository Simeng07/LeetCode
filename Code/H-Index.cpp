class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        for (int i = 1; i <= citations.size(); i++) {
            if (i > citations[citations.size() - i]) return i - 1;
        }
        return citations.size();
    }
};