class Solution {
    struct Status {
        int x;
        int y;
        int d;
    };
public:
    bool isRobotBounded(string instructions) {
        Status status;
        status.x = 0;
        status.y = 0;
        status.d = 0;
        while (true) {
            for (const auto &c : instructions) {
                if (c == 'G') {
                    switch (status.d) {
                        case 0:
                            status.y++;
                            break;
                        case 1:
                            status.x++;
                            break;
                        case 2:
                            status.y--;
                            break;
                        case 3:
                            status.x--;
                            break;
                        default:
                            break;   
                    }
                } else if (c == 'L') {
                    status.d--;
                    if (status.d == -1) {
                        status.d = 3; // status.d %= 4 不好使啊
                    }
                } else if (c == 'R') {
                    status.d++;
                    status.d %= 4;
                }
                // cout << c << " " << status.x << " " << status.y << " " << status.d << endl;
            }
            if (status.d == 0) {
                if (status.x == 0 && status.y == 0) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;
    }
};