class Robot {
    int w, h, mod;
    int pos;
    bool hasMoved = false;
public:
    Robot(int width, int height) {
        w = width;
        h = height;
        pos = 0;
        mod = (w + h - 2) * 2;
    }
    
    void move(int num) {
        hasMoved = true;
        pos = (pos + num) % mod;
    }
    
    vector<int> getPos() {
        if (pos == 0) {
            return {0, 0};
        }
        if (pos <= w - 1) {
            return {pos, 0};
        }
        if (pos > w - 1 && pos <= mod / 2) {
            return {w - 1, pos - (w - 1)};
        }
        if (pos > mod / 2 && pos <= mod / 2 + w - 1) {
            return {(mod / 2 + w - 1 - pos), h - 1};
        }
        return {0, mod - pos};
    }
    
    string getDir() {
        if (pos == 0) {
            if (hasMoved) {
                return "South";
            } else {
                return "East";
            }
        }
        if (pos <= w - 1) {
            return "East";
        }
        if (pos > w - 1 && pos <= mod / 2) {
            return "North";
        }
        if (pos > mod / 2 && pos <= mod / 2 + w - 1) {
            return "West";
        }
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */