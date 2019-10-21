class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // eg. 123456781
        // among 234, 2>0, 23>0, 234>0，2345<0，then 6781 must>0，then 6781234>0，start from 6
        int result = 0;
        int tmpSum = 0;
        int sum = 0;
        for (int i = 0; i < gas.size(); i++) {
            tmpSum += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (tmpSum < 0) {
                result = i + 1;
                tmpSum = 0;
            }
        }
        return sum >= 0 ? result : -1;
    }
};