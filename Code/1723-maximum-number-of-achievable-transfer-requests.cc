class Solution {
    int result = 0;
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> v(n, 0);
        helper(requests, 0, 0, v);
        return result;
    }
    
    void helper(vector<vector<int>>& requests, int index, int move, vector<int> &current) {
        if (index == requests.size()) {
            for (int i = 0; i < current.size(); i++) {
                if (current[i] != 0) {
                    return;
                }
            }
            result = max(result, move);
            return;
        }
        
        current[requests[index][0]]--;
        current[requests[index][1]]++;
        helper(requests, index + 1, move + 1, current);
        current[requests[index][0]]++;
        current[requests[index][1]]--;
        helper(requests, index + 1, move, current);
    }
};