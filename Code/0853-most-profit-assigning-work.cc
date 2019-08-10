class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        if (worker.size() == 0 || difficulty.size() == 0) {
            return 0;
        }
        sort(worker.begin(), worker.end());
        vector<pair<int, int> > resource;
        for (int i = 0; i < difficulty.size(); i++) {
            resource.push_back({difficulty[i], profit[i]});
        }
        sort(resource.begin(), resource.end());
        
        int result = 0;
        int currentMax = 0;
        
        auto it = resource.begin();
        for (auto w : worker) {
            while (w >= it->first && it != resource.end()) {
                currentMax = max(currentMax, it->second);
                it++;
            }
            result += currentMax;
        }
        
        return result;
    }
};
