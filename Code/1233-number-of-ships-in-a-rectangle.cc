/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
    int total = 0;
    bool find = false;
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        helper(sea, topRight, bottomLeft);
        return total;
    }
    void helper(Sea &sea, vector<int> topRight, vector<int> bottomLeft) {
        // cout << bottomLeft[0] << " " << bottomLeft[1] << " " << topRight[0] << " " << topRight[1] << endl;
        if (find) {
            return;
        }
        bool has = sea.hasShips(topRight, bottomLeft);
        if (has) {
            if (topRight[0] == bottomLeft[0] && topRight[1] == bottomLeft[1]) {
                total++;
                if (total == 10) {
                    find = true;
                }
                return;
            }
            if (has) {
                int x = (topRight[0] + bottomLeft[0]) / 2;
                int y = (topRight[1] + bottomLeft[1]) / 2;
                helper(sea, {x, y}, {bottomLeft[0], bottomLeft[1]});
                if (x + 1 <= topRight[0]) {
                    helper(sea, {topRight[0], y}, {x + 1, bottomLeft[1]});
                }
                if (y + 1 <= topRight[1]) {
                    helper(sea, {x, topRight[1]}, {bottomLeft[0], y + 1});
                }
                if (x + 1 <= topRight[0] && y + 1 <= topRight[1]) {
                    helper(sea, {topRight[0], topRight[1]}, {x + 1, y + 1});
                }
            }
        }
    }
};