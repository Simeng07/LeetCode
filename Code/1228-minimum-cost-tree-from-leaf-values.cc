class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int result = 0;
        stack<int> s;
        s.push(INT_MAX);
        arr.push_back(INT_MAX);
        
        for (auto num : arr) {
            while (num > s.top()) {
                int top = s.top();
                s.pop();
                int last = s.top();
                if (last == INT_MAX && num == INT_MAX) {
                    return result;
                }
                result += min(num, last) * top;
            }
            s.push(num);
        }
        
        return result;
    }
};