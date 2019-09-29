class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if (answers.size() == 0) {
            return 0;
        }
        if (answers.size() == 1) {
            return answers[0] + 1;
        }
        
        int count[1000] = {0};
        for (auto answer : answers) {
            count[answer]++;
        }
        
        int result = 0;
        for (int i = 0; i < 1000; i++) {
            result += ceil((double)count[i] / (i + 1)) * (i + 1);
        }
        
        return result;
    }
};