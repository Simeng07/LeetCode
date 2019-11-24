class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result(searchWord.size());
        sort(products.begin(), products.end());
        string current = "";
        int lastIndex = 0;
        for (int i = 0; i < searchWord.size(); i++) {
            current += searchWord[i];
            auto it = lower_bound(products.begin() + lastIndex, products.end(), current);
            if (it == products.end() || ((*it).find(current) != 0)) {
                break;
            }
            lastIndex = it - products.begin();
            for (int j = 0; j < 3; j++) {
                if (j == 0 || (*it).find(current) == 0) {
                    result[i].push_back(*it);
                    it++;
                    if (it == products.end()) {
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        return result;
    }
};