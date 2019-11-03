class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        queue<int> q;
        int ocount = 0;
        int result = 0;
        int ecount = 1;
        for (auto num : nums) {
            q.push(num);
            if (num & 1) {
                ocount++;
                if (ocount == k) {
                    while (!q.empty()) {
                        int front = q.front();
                        if (!(front & 1)) {
                            ecount++;
                            q.pop();
                        } else {
                            break;
                        }
                    }
                    result += ecount;
                }
                if (ocount == k + 1) {
                    q.pop();
                    ocount--;
                    ecount = 1;
                    while (!q.empty()) {
                        int front = q.front();
                        if (!(front & 1)) {
                            ecount++;
                            q.pop();
                        } else {
                            break;
                        }
                    }
                    result += ecount;
                    // cout << "ecount " << ecount<< endl;
                }
                
            } else {
                if (ocount == k) {
                    result += ecount;
                }
            }
        }
        return result;
    }
};