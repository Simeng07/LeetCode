class Solution {
    vector<int> result;
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end());
        dfs(n, sums);
        return result;
    }
    bool dfs(int n, vector<int>& sums) {
        if (n == 0) {
            return true;
        }
        int diff = sums[1] - sums[0]; // what if sums.size() == 1 -> won't. size will be 2^n
        int mask = 0; // to see whether diff or -diff exists
        for (auto sum : sums) {
            if (sum == diff) {
                mask |= 1;
            } else if (sum == -diff) {
                mask |= 2;
            }
        }
        if (!mask) {
            return false;
        }
        
        vector<int> smaller, bigger;
        queue<int> q;
        for (auto sum : sums) {
            if (!q.empty() && q.front() == sum) {\
                // has added to bigger
                q.pop();
                continue;
            }
            // add to smaller. add x + diff to bigger
            smaller.push_back(sum);
            bigger.push_back(sum + diff);
            q.push(sum + diff);
        }
        
        if (mask & 1) {
            // diff exists. use smaller which not contains diff
            result.push_back(diff);
            if (dfs(n - 1, smaller)) {
                return true;
            }
            result.pop_back();
        }
        if (mask & 2) {
            // -diff exists. use bigger which not contains diff
            result.push_back(-diff);
            if (dfs(n - 1, bigger)) {
                return true;
            }
            result.pop_back();
        }
        
        return false;
    }
};