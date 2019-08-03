class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int maxCount = 0;
        long totalCount = 0;
        for (auto pile : piles) {
            if (pile > maxCount) {
                maxCount = pile;
            }
            if (totalCount <= H) {
                totalCount += pile;
            }
        }
        
        if (totalCount <= H) {
            return 1;
        }
        
        int minSpeed = 1;
        int maxSpeed = maxCount;
        
        int middle = minSpeed + (maxSpeed - minSpeed) / 2;
        
        while (true) {
            int time = 0;
            for (auto pile : piles) {
                time += ceil(pile * 1.0 / middle);
            }
            if (time > H) {
                minSpeed = middle;
            } else {
                maxSpeed = middle;
            }
            middle = minSpeed + (maxSpeed - minSpeed) / 2;
            if (minSpeed == middle) {
                return maxSpeed;
            }
        }
        
        return 0;
    }
};