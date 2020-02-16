class Solution {
public:
    bool isPossible(vector<int>& target) {
        int size = target.size();
        
        long long sum = 0;
        for (int i = 0; i < size; i++) {
            sum += target[i];
        }
        
        if ((sum - size) % (size - 1) != 0) {
            return false;
        }
        
        priority_queue<int> pq(target.begin(), target.end());
        
        while (true) {
            int maxNum = pq.top();
            if (maxNum == 1) {
                return true;
            }
            pq.pop();
            
            int lastMax = maxNum - (sum - maxNum);
            if (lastMax <= 0) {
                return false;
            }
            
            sum += (lastMax - maxNum);
            pq.push(lastMax);
        }
        return false;
    }
};