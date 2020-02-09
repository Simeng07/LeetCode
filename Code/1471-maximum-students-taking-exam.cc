class Solution {
    int result = 0;
    unordered_map<string, int> map;
public:
    int maxStudents(vector<vector<char>>& seats) {
        helper(seats, 0, 0);
        return result;
    }
    
    void helper(vector<vector<char>>& seats, int index, int count) {
        int m = seats.size();
        int n = seats[0].size();
        
        if (index == m * n) {
            result = max(result, count);
            return;
        }
        int i = index / n;
        int j = index % n;
        
        if (j == 0 && i != 0) {
            string row = to_string(i);
            for (int k = 0; k < n; k++) {
                row += seats[i - 1][k];
            }
            if (map.find(row) != map.end() && map[row] >= count) {
                return;
            }
            map[row] = count;
        }
        
        if (seats[i][j] == '#') {
            helper(seats, index + 1, count);
            return;
        }
        
        bool isValid = true;
        if (j - 1 >= 0) {
            if (i - 1 >= 0 && seats[i - 1][j - 1] == 'a') {
                isValid = false;
            }
            if (seats[i][j - 1] == 'a') {
                isValid = false;
            }
        }
        if (j + 1 < n) {
            if (i - 1 >= 0 && seats[i - 1][j + 1] == 'a') {
                isValid = false;
            }
            if (seats[i][j + 1] == 'a') {
                isValid = false;
            }
        }
        if (isValid) {
            seats[i][j] = 'a';
            helper(seats, index + 1, count + 1);
            seats[i][j] = '.';
        }
        helper(seats, index + 1, count);
    }
};