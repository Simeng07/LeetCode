class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if (x.size() <= 3) return false;
        unordered_map<int, set<pair<int, int>>> mx;
        unordered_map<int, set<pair<int, int>>> my;
        int currentx = 0;
        int currenty = 0;
        int direction = 0;
        for (int i = 0; i < x.size(); i++) {
            if (direction % 2 == 0) {
                // vertical
                int updatedy = currenty + ((direction == 0) ? x[i] : -x[i]);
                for (auto it = my.begin(); it != my.end(); it++) 
                    // horizontal lines
                    if ((it->first >= min(currenty, updatedy)) && (it->first <= max(currenty, updatedy)) && it->first != currenty) 
                        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) 
                            if ((currentx >= min(it2->first, it2->second)) && (currentx <= max(it2->first, it2->second))) 
                                return true;
                for (auto it = mx[currentx].begin(); it != mx[currentx].end(); it++) 
                    // vertical lines
                    if (!((min(it->first, it->second)) > max(currenty, updatedy) || (max(it->first, it->second)) < min(currenty, updatedy)))
                        return true;
                mx[currentx].insert(make_pair(currenty, updatedy));
                currenty = updatedy;
            } else {
                // horizontal
                int updatedx = currentx + ((direction == 1) ? -x[i] : x[i]);
                for (auto it = mx.begin(); it != mx.end(); it++) 
                    // vertical lines
                    if ((it->first >= min(currentx, updatedx)) && (it->first <= max(currentx, updatedx)) && it->first != currentx) 
                        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) 
                            if ((currenty >= min(it2->first, it2->second)) && (currenty <= max(it2->first, it2->second))) 
                                return true;
                for (auto it = my[currenty].begin(); it != my[currenty].end(); it++) 
                    // horizontal lines
                    if (!((min(it->first, it->second)) > max(currentx, updatedx) || (max(it->first, it->second)) < min(currentx, updatedx))) return true;
                my[currenty].insert(make_pair(currentx, updatedx));
                currentx = updatedx;
            }
            direction = (++direction) % 4;
        }
        return false;
    }
};