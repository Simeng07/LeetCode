class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> result;
        if (tomatoSlices > cheeseSlices * 4 || tomatoSlices < cheeseSlices * 2 || tomatoSlices % 2 == 1) {
            return result;
        }
        int jcount = tomatoSlices / 2 - cheeseSlices;
        return {jcount, cheeseSlices - jcount};
    }
};