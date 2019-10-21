class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.size() <= 1) return ratings.size();
        int p = 0;
        int result = 1;
        int currentNum = 1;
        int highest = 1;
        bool isUp = ratings[1] >= ratings[0];
        for (int i = 1; i < ratings.size(); i++) {
            if (isUp) {
                if (ratings[i] > ratings[i-1]) {
                    currentNum++;
                    result += currentNum;
                } else {
                    p = i;
                    isUp = false;
                    highest = currentNum;
                    currentNum =  0;
                }
            } else {
                if (ratings[i] < ratings[i-1]) {
                    currentNum--; // could be negative
                    result += currentNum;
                } else {
                    isUp = true;
                    result += (i - p) * (1 - currentNum); // handle the negative and too large nums
                    if (highest <= i - p && (p > 0 && ratings[p] < ratings[p - 1])) result += i - p - highest + 1;
                    currentNum = (ratings[i] == ratings[i-1]) ? 1 : 2;
                    result += currentNum;
                    p = i;
                }
            }
        }
        if (!isUp) {
            if (highest <= ratings.size() - p && (p > 0 && ratings[p] < ratings[p - 1])) result += ratings.size() - p - highest + 1;
            result += (ratings.size() - p) * (1 - currentNum);
        }
        return result;
    }
};