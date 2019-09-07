class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if (N == 0) {
            return cells;
        }
        
        short i2v[128];
        short v2i[256];
        bool has[256];
        memset(i2v, 0, sizeof(i2v));
        memset(v2i, 0, sizeof(v2i));
        memset(has, false, sizeof(has));
        
        short t = transToShort(cells);
        i2v[0] = t;
        v2i[t] = 0;
        
        short i = 1;
        short last = t;
        short current;
        while (true) {
            current = cal(last);
            if (has[current]) {
                break;
            } else {
                i2v[i] = current;
                v2i[current] = i;
                has[current] = true;
            }
            last = current;
            if (i == N) {
                return transToVector(current);
            }
            i++;
        }
        
        return transToVector(i2v[(N - i) % (i - v2i[current]) + v2i[current]]);
    }
    
    short cal(short cells) {
        short result = 0;
        for (int i = 2; i < 128; i <<= 1) {
            int left = ((cells & (i << 1)) > 0) ? 1: 0;
            int right = ((cells & (i >> 1)) > 0) ? 1: 0;
            result |= (left == right) ? i : 0;
        }
        return result;
    }
    
    short transToShort(vector<int>& cells) {
        if (cells.size() != 8) {
            return 0;
        }
        short result = 0;
        int tmp = 1;
        for (int i = 7; i >= 0; i--) {
            result |= ((cells[i] > 0) ? tmp : 0);
            tmp <<= 1;
        }
        return result;
    }
    
    vector<int> transToVector(short num) {
        vector<int> result;
        int tmp = (1 << 7);
        while (tmp != 0) {
            result.push_back(((tmp & num) > 0) ? 1 : 0);
            tmp >>= 1;
        }
        return result;
    }
};