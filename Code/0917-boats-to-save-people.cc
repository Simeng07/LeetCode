class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int p = 0, q = people.size() - 1, result = 0;
        
        while (p <= q) {
            if (people[q] + people[p] <= limit) {
                p++;
            }
            q--;
            result++;
        }
        
        return result;
    }
};