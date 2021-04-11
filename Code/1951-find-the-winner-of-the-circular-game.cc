class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1) {
            return 1;
        }
        if (k == 1) {
            return n;
        }
        vector<int> person;
        for (int i = 0; i < n; i++) {
            person.push_back(i + 1);
        }
        int start = 0;
        while (person.size() > 1) {
            int realK = (start + k - 1) % person.size();
            start = realK;
            person.erase(person.begin() + realK);
        }
        return person[0];
    }
};