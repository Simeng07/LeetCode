class Solution {
public:
    vector<int> asteroidCollision(vector<int> asteroids) {
        vector<int> result;
        for (auto asteroid : asteroids) {
            while (true) {
                if (result.empty() || asteroid > 0) {
                    result.push_back(asteroid);
                    break;
                }
                int last = result.back();
                if (asteroid * last < 0) {
                    if (last < -asteroid) {
                        result.pop_back();
                    } else if (last > -asteroid) {
                        break;
                    } else {
                        result.pop_back();
                        break;
                    }
                } else {
                    result.push_back(asteroid);
                    break;
                }
            }
        }
        return result;
    }
};