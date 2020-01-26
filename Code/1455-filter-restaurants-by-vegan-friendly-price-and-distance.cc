class Solution {
    static bool myCompare(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> choose;
        for (auto &restaurant : restaurants) {
            if ((veganFriendly == 0 || restaurant[2] == 1)
                && maxPrice >= restaurant[3]
                && maxDistance >= restaurant[4]) {
                choose.push_back({restaurant[1], restaurant[0]});
            }
        }
        
        sort(choose.begin(), choose.end(), myCompare);
        
        vector<int> result;
        for (auto &p : choose) {
            result.push_back(p.second);
        }
        
        return result;
    }
};