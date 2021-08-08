class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue <int, vector<int>, less<int>> pq ;
        for (auto pile : piles) {
            pq.push(pile);
        }
        while (k-- > 0) {
            int top = pq.top();
            pq.pop();
            top -= top / 2;
            pq.push(top);
        }
        int result = 0;
        while (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
        return result;
    }
};