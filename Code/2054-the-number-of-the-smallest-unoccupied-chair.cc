class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int target = times[targetFriend][0];
        sort(times.begin(), times.end());
        set<int> s;
        for (int i = 0; i < target + 2; i++) {
            s.insert(i);
        }
        set<pair<int, int>> toLeave;
        for (int i = 0; i < times.size(); i++) {
            auto it = toLeave.begin();
            while (it != toLeave.end() && it->first <= times[i][0]) {
                s.insert(it->second);
                toLeave.erase(it);
                it = toLeave.begin();
            }
            
            int chair = *s.begin();
            if (times[i][0] == target) {
                return chair;
            }
            
            toLeave.insert({times[i][1], chair});
            s.erase(chair);
        }
        
        return 0;
    }
};