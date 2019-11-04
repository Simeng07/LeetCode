class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        if (input.length() == 0) return result;
        for (int i = 0; i < input.length(); i++) {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (auto n1: left) {
                    for (auto n2 : right) {
                        if (c == '+')
                            result.push_back(n1 + n2);
                        else if (c == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2); 
                    }
                }
            }
        }
        if (result.size() == 0)
            result.push_back(stoi(input));
        return result;
    }
};