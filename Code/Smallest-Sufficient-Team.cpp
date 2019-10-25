class Solution {
    unordered_map<string, int> m;
    uint16_t need = 0;
    uint64_t result;
    uint64_t dp[61][65537] = {0};
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int count = 0;
        for (auto &skill : req_skills) {
            m[skill] = count;
            need |= (1 << count);
            count++;
        }
        uint64_t base = 1;
        for (int i = 0; i < people.size(); i++) {
            result |= (base << i);
        }
        helper(people, 0, 0, 0);
        vector<int> pr;
        for (int i = 0; i < people.size(); i++) {
            if (result & (base << i)) {
                pr.push_back(i);
            }
        }
        return pr;
    }
    
    void helper(vector<vector<string>>& people, int index, uint16_t current, uint64_t chose) {
        if (dp[index][current] != 0 && countBits(chose) > countBits(dp[index][current])) {
            return;
        }
        dp[index][current] = chose;
        
        if (index == people.size()) {
            if ((current & need) == need) {
                if (countBits(result) > countBits(chose)) {
                    result = chose;
                }
            }
            return;
        }
        
        uint16_t can = 0;
        uint64_t base = 1;
        if (people[index].size() > 0) {
            for (auto &skill : people[index]) {
                can |= (base << m[skill]);
            }
        }
        
        helper(people, index + 1, current, chose);
        
        int total = (current | can);
        if (total != current) {
            chose |= (base << index);
            helper(people, index + 1, total, chose);
        }
    }
    
    int countBits(uint64_t n) {
        int count = 0;
        while (n != 0) {
            n = n & (n-1);
            count++;
        }
        return count;
    }
};