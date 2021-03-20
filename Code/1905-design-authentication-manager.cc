class AuthenticationManager {
    unordered_map<string, int> id2t; // {id, expireTime}
    map<int, unordered_set<string>> t2id; // {expireTime, ids}
    int t2l;
public:
    AuthenticationManager(int timeToLive) {
        t2l = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        int expireTime = currentTime + t2l;
        id2t[tokenId] = expireTime;
        t2id[expireTime].insert(tokenId);
    }
    
    void renew(string tokenId, int currentTime) {
        if (id2t.find(tokenId) != id2t.end()) {
            if (id2t[tokenId] > currentTime) {
                t2id[id2t[tokenId]].erase(tokenId);
                int expireTime = currentTime + t2l;
                id2t[tokenId] = expireTime;
                t2id[expireTime].insert(tokenId);
            }
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        unordered_set<int> toDelete;
        auto it = t2id.begin();
        while (it != t2id.end()) {
            int expireTime = it->first;
            if (expireTime > currentTime) {
                break;
            }
            cout << expireTime << endl;
            for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
                id2t.erase(*it2);
            }
            t2id.erase(it);
            it = t2id.begin();
        }
        return id2t.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */