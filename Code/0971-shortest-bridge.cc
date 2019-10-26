class Solution {
    queue<pair<int, int>> q;
    int result;
    bool ok;
    int gap[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    int shortestBridge(vector<vector<int>>& A) {
        int size = A.size();
        bool find = false;
        int i, j;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                if (A[i][j] == 1) {
                    find = true;
                    break;
                }
            }
            if (find) {
                break;
            }
        }
        // the first 1
        helper(A, i, j);
        result = 3;
        int count = q.size();
        
        while (!q.empty()) {
            result++;
            while (count--) {
                handle(A, q.front().first, q.front().second, result); // color the outer border as result(4+)
                q.pop();
                if (ok) {
                    return result - 3;
                }
            }
            count = q.size();
        }
        return result - 3;
    }
    
    void handle(vector<vector<int>>& A, int a, int b, int current) {
        for (int i = 0; i < 4; i++) {
            int aa = a + gap[i][0], bb = b + gap[i][1];
            if (aa >= 0 && aa < A.size() && bb >= 0 && bb < A.size()) {
                if (A[aa][bb] == 1) {
                    ok = true;
                    return;
                }
                if (A[aa][bb] == 0) {
                    A[aa][bb] = current;
                    q.push({aa, bb});
                }
            }
        }
    }
    
    // change all 1s in one union to 2, and get their border(3)
    void helper(vector<vector<int>>& A, int a, int b) {
        if (A[a][b] == 0) {
            A[a][b] = 3;
            q.push({a, b});
            return;
        }
        if (A[a][b] == 1) {
            A[a][b] = 2;
            for (int i = 0; i < 4; i++) {
                int aa = a + gap[i][0], bb = b + gap[i][1];
                if (aa >= 0 && aa < A.size() && bb >= 0 && bb < A.size()) {
                    helper(A, aa, bb);
                }
            }
        }
    }
};