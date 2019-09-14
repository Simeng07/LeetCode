class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int size = hand.size();
        if (size % W != 0) {
            return false;
        }
        int patch = size / W;
        
        multiset<int> s(hand.begin(), hand.end());
        
        for (int i = 0; i < size / W; i++) {
            int begin = *s.begin();
            s.erase(s.begin());
            for (int j = 1; j < W; j++) {
                auto next = s.find(begin + j);
                if (next == s.end()) {
                    return false;
                } else {
                    s.erase(next);
                }
            }
        }
        
        return true;
    }
};