class Solution {
    //  O(N log N) Fenwick/BIT
    int used[30001] = {0};
    int n;
    
    int getSum(int index) {
        int sum = 0;
        while (index > 0) {
            sum += used[index];
            index -= (index & -index);
        }
        return sum;
    }
    
    void updateBIT(int index, int value) {
        while (index <= n) {
            used[index] += value;
            index += (index & -index);
        }
    }
    
public:
    string minInteger(string num, int k) {
        string sortedNum = num;
        sort(sortedNum.begin(), sortedNum.end());
        if (num == sortedNum) {
            return num;
        }
        
        string result = "";
        n = num.size();
        priority_queue<int, vector<int>, greater<int>> nums[10];
        for (int i = 0; i < num.size(); i++) {
            nums[num[i] - '0'].push(i + 1);
        }
        
        int moves = 0;
        while (moves < n && k > 0) {
            for (int i = 0; i <= 9; i++) {
                if (nums[i].empty()) {
                    continue;
                }
                int index = nums[i].top();
                int holes = getSum(index - 1);
                int move = index - holes - 1;
                if (move <= k) {
                    result += ('0' + i);
                    k -= move;
                    updateBIT(index, 1);
                    nums[i].pop();
                    break;
                }
            }
            moves++;
        }
        
        vector<pair<int, int>> left;
        for (int i = 0; i <= 9; i++) {
            while (!nums[i].empty()) {
                left.push_back(make_pair(nums[i].top(), i));
                nums[i].pop();
            }
        }
        
        sort(left.begin(), left.end());
        
        for (auto &p : left) {
            result += ('0' + p.second);
        }
        
        return result;
    }
};