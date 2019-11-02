class Leaderboard {
    int ptos[10001] = {0};
    map<int, int, greater<int>> stop;
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        int old = ptos[playerId];
        if (old != 0) {
            stop[old]--;
            if (stop[old] == 0) {
                stop.erase(old);
            }
        }
        ptos[playerId] += score;
        stop[ptos[playerId]]++;
    }
    
    int top(int K) {
        int result = 0;
        for (auto it = stop.begin(); it != stop.end(); ++it) {
            cout << it->first << " " << it->second << endl;
            if (it->second > K) {
                result += (K * it->first);
                return result;
            } else {
                result += (it->second * it->first);
            }
            K -= it->second;
        }
        return result;
    }
    
    void reset(int playerId) {
        int old = ptos[playerId];
        if (old != 0) {
            stop[old]--;
            if (stop[old] == 0) {
                stop.erase(old);
            }
        }
        ptos[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */