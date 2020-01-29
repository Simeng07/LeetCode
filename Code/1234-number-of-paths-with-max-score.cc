class Solution {
    
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int size = board.size();
        int mod = 1000000007;
        vector<int> sum = vector<int>(size, 0);
        vector<int> tmpSum = sum;
        vector<int> count = vector<int>(size, 0);
        count[size - 1] = 1;
        vector<int> tmpCount = count;
        
        for (int i = size - 1; i >= 0; i--) {
            for (int j = size - 1; j >= 0; j--) {
                if (i == size - 1 && j == size - 1) {
                    continue;
                }
                
                if (board[i][j] == 'X') {
                    sum[j] = -1;
                    count[j] = -1;
                    continue;
                }
                
                int roundSum = -1, roundCount = -1;
                // horizontal
                if (j != size - 1 && board[i][j + 1] != 'X' && sum[j + 1] != -1) {
                    roundSum = sum[j + 1] + (board[i][j] - '0');
                    roundCount = count[j + 1];
                }
                // vertical
                if (i != size - 1 && board[i + 1][j] != 'X' && tmpSum[j] != -1) {
                    if (tmpSum[j] + (board[i][j] - '0') > roundSum) {
                        roundSum = tmpSum[j] + (board[i][j] - '0');
                        roundCount = tmpCount[j];
                    } else if (tmpSum[j] + (board[i][j] - '0') == roundSum) {
                        roundCount += tmpCount[j];
                        roundCount %= mod;
                    }
                }
                // diagonal
                if (i != size - 1 && j != size - 1 && board[i + 1][j + 1] != 'X' && tmpSum[j + 1] != -1) {
                    if (tmpSum[j + 1] + (board[i][j] - '0') > roundSum) {
                        roundSum = tmpSum[j + 1] + (board[i][j] - '0');
                        roundCount = tmpCount[j + 1];
                    } else if (tmpSum[j + 1] + (board[i][j] - '0') == roundSum) {
                        roundCount += tmpCount[j + 1];
                        roundCount %= mod;
                    }
                }
                
                sum[j] = roundSum;
                count[j] = roundCount;
            }
            tmpSum = sum;
            tmpCount = count;
        }
        
        if (sum[0] <= 0) {
            return {0, 0};
        }
        return {sum[0] - ('E' - '0'), count[0]};
    }
};